//
// File: DirectionTool.h
// Author:lyk
// Date: 2016/03/21
// Desc: 向量的方向计算
//

#ifndef DIRECTIONTOOL_H
#define DIRECTIONTOOL_H

#include "Export.h"
#include <osg/Geometry>

class MANIPULOTOR_EXPORT DirRelation
{
public:
	enum DirRel
	{
		SAME_DIR = 0,		
		RESERVE_DIR,		
		ANGLE_DIR			
	};

	static bool isSameDir(osg::Vec3 dir1, osg::Vec3 dir2)
	{ return SAME_DIR == getDirRelation(dir1, dir2); }
	static bool isReverseDir(osg::Vec3 dir1, osg::Vec3 dir2)
	{ return RESERVE_DIR == getDirRelation(dir1, dir2); }
	static bool isAngleDir(osg::Vec3 dir1, osg::Vec3 dir2)
	{ return ANGLE_DIR == getDirRelation(dir1, dir2); }

	static bool isSameOrReverseDir(osg::Vec3 dir1, osg::Vec3 dir2)
	{
		DirRel rel = getDirRelation(dir1, dir2);
		return (SAME_DIR == rel || RESERVE_DIR == rel);
	}
	static DirRel  getDirRelation(osg::Vec3 dir1, osg::Vec3 dir2)
	{
		dir1.normalize(); dir2.normalize();

		// zero vector exists
		if (dir1.length() < 0.001 || dir2.length() < 0.001) return SAME_DIR;

		// same or reserve 
		for (size_t i = 0; i != 3; ++i)
		{
			if (fabs(dir1[i]) - fabs(dir2[i]) > 0.001) return ANGLE_DIR;
		}

		float val = dir1 * dir2 / dir1.length() / dir2.length();

		if (val > 0.999) return SAME_DIR;
		if (val < -0.999) return RESERVE_DIR;
		return ANGLE_DIR;

		// the vector which can reach here it's fabs is equal
		if(dir1.x()*dir2.x()>=0 && dir1.y()*dir2.y()>=0 && dir1.z()*dir2.z()>=0) return SAME_DIR;
		else if (dir1.x()*dir2.x()<=0 && dir1.y()*dir2.y()<=0 && dir1.z()*dir2.z()<=0) return RESERVE_DIR;
		else return ANGLE_DIR;
	}
};

class MANIPULOTOR_EXPORT DirectionTool
{
public:
	enum Axis
	{
		NONE_AXIS,
		AXIS_X,
		NEG_AXIS_X,
		AXIS_Y,
		NEG_AXIS_Y,
		AXIS_Z,
		NEG_AXIS_Z
	};
	enum Plane
	{
		XY_PLANE,
		YZ_PLANE,
		ZX_PLANE,
		OTHER_PLANE
	};
	static bool isDirAxis(const osg::Vec3& dir)
	{
		return 	DirRelation::isSameOrReverseDir(dir, osg::X_AXIS) ||
				DirRelation::isSameOrReverseDir(dir, osg::Y_AXIS) ||
				DirRelation::isSameOrReverseDir(dir, osg::Z_AXIS);
	}

	static Plane getDirInAxisPlane( const osg::Vec3& dir )
	{
		if (abs(dir.x()) < 0.0001) return YZ_PLANE;
		if (abs(dir.y()) < 0.0001) return ZX_PLANE;
		if (abs(dir.z()) < 0.0001) return XY_PLANE;

		return OTHER_PLANE;
	}

	static Axis getClosestAxis(const osg::Vec3& dir)
	{
		if (getCos(osg::X_AXIS, dir) > 0.9)
		{
			return AXIS_X;
		}
		else if (getCos(osg::Y_AXIS, dir) > 0.9)
		{
			return AXIS_Y;
		}
		else if (getCos(osg::Z_AXIS, dir) > 0.9)
		{
			return AXIS_Z;
		}
		else if (getCos(-osg::X_AXIS, dir) > 0.9)
		{
			return NEG_AXIS_X;
		}
		else if (getCos(-osg::Y_AXIS, dir) > 0.9)
		{
			return NEG_AXIS_Y;
		}
		else if (getCos(-osg::Z_AXIS, dir) > 0.9)
		{
			return NEG_AXIS_Z;
		}

		return NONE_AXIS;

	}

	static osg::Vec3 getClosestAxisDir(const osg::Vec3& dir)
	{
		if (getCos(osg::X_AXIS, dir) > 0.9)
		{
			return osg::X_AXIS;
		}
		else if (getCos(osg::Y_AXIS, dir) > 0.9)
		{
			return osg::Y_AXIS;
		}
		else if (getCos(osg::Z_AXIS, dir) > 0.9)
		{
			return osg::Z_AXIS;
		}
		else if (getCos(-osg::X_AXIS, dir) > 0.9)
		{
			return -osg::X_AXIS;
		}
		else if (getCos(-osg::Y_AXIS, dir) > 0.9)
		{
			return -osg::Y_AXIS;
		}
		else if (getCos(-osg::Z_AXIS, dir) > 0.9)
		{
			return -osg::Z_AXIS;
		}

		return osg::Z_AXIS;
	}

	// 直接一个上方向, 除非和Z轴平行, 不然都是Z轴
	static osg::Vec3 getStrictUpDir(const osg::Vec3& trgDir)
	{
		if (trgDir.length2() < 0.001) return osg::Z_AXIS;

		if (DirRelation::isSameDir(trgDir, osg::Z_AXIS))
		{
			return -osg::Y_AXIS;
		}
		else if (DirRelation::isSameDir(trgDir, -osg::Z_AXIS))
		{
			return osg::Y_AXIS;
		}

		return osg::Z_AXIS;
	}

	// 自动计算上方向
	static osg::Vec3 getUpDir( const osg::Vec3& trgDir )
	{
		// 如果是空向量, 返回+Z
		if (trgDir.length2() < 0.001) return osg::Z_AXIS;

		// 如果和Z轴平行
		if (DirRelation::isSameDir(trgDir, osg::Z_AXIS))
		{
			return -osg::Y_AXIS;
		}
		else if (DirRelation::isSameDir(trgDir, -osg::Z_AXIS))
		{
			return osg::Y_AXIS;
		}

		// 叉乘计算
		osg::Vec3 aidDir = trgDir ^ osg::Z_AXIS;
		osg::Vec3 upDir = aidDir ^ trgDir; upDir.normalize();

		return upDir;
	}

	// 去最近的一个方向作为上方向, 如果和Z轴平行, 就使用nearUpDir
	static osg::Vec3 getUpDir(const osg::Vec3& forDir, const osg::Vec3& nearUpDir)
	{
		if (forDir.length() < 0.0001) return osg::Z_AXIS;
		if (DirRelation::isSameOrReverseDir(forDir, osg::Z_AXIS))
		{
			return getClosestAxisDir(nearUpDir);
		}

		osg::Vec3 aidDir = forDir ^ osg::Z_AXIS;
		osg::Vec3 upDir = aidDir ^ forDir; upDir.normalize();

		return upDir;
	}

	// 计算左手边方向
	static osg::Vec3 getLeftDir(const osg::Vec3& trgDir)
	{
		if (trgDir.length2() < 0.001) return osg::Z_AXIS;

		if (DirRelation::isSameDir(trgDir, osg::Z_AXIS))
		{
			return -osg::X_AXIS;
		}
		else if (DirRelation::isSameDir(trgDir, -osg::Z_AXIS))
		{
			return -osg::X_AXIS;
		}

		return osg::Z_AXIS ^ trgDir;
	}

	// 计算右手边方向
	static osg::Vec3 getRightDir(const osg::Vec3& trgDir)
	{
		if (trgDir.length2() < 0.001) return osg::Z_AXIS;

		if (DirRelation::isSameDir(trgDir, osg::Z_AXIS))
		{
			return osg::X_AXIS;
		}
		else if (DirRelation::isSameDir(trgDir, -osg::Z_AXIS))
		{
			return osg::X_AXIS;
		}

		return trgDir ^ osg::Z_AXIS;
	}


	// 未实现
	static osg::Vec3 getLookUpDir(osg::Matrix mtx)
	{
		return osg::Vec3();
	}
	static osg::Vec3 getLookDownDir(osg::Matrix mtx)
	{
		return osg::Vec3();		
	}
	static osg::Vec3 getLookLeftDir(osg::Matrix mtx)
	{
		return osg::Vec3();	
	}
	static osg::Vec3 getLookRightDir(osg::Matrix mtx)
	{
		return osg::Vec3();	
	}

	// 得到一个Plane
	static osg::Plane getPlaneByLookDirAndDirInPlane(const osg::Vec3& lookDir, const osg::Vec3& dirInPlane, const osg::Vec3 & pos)
	{
		if ( DirRelation::isAngleDir(lookDir, dirInPlane))
		{
			osg::Vec3 upDir = getUpDir(dirInPlane);
			return osg::Plane(upDir, pos);
		}

		osg::Vec3 upDir = lookDir ^ dirInPlane;
		return osg::Plane(upDir, pos);
	}

	static double getCos(const osg::Vec3& dir1, const osg::Vec3& dir2)
	{
		return dir1 * dir2 / dir1.length() / dir2.length();
	}

	static double getCosRadian(const osg::Vec3& dir1, const osg::Vec3& dir2)
	{
		return acos(getCos(dir1, dir2));
	}
};

#endif // DIRECTIONTOOL_H
