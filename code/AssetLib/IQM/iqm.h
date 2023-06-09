#ifndef __IQM_H__
#define __IQM_H__

#define IQM_MAGIC "INTERQUAKEMODEL"
#define IQM_VERSION 2

#include <stdint.h>

struct iqmheader
{
    char magic[16];
    //unsigned int version;
    //unsigned int filesize;
    //unsigned int flags;
    //unsigned int num_text, ofs_text;
    //unsigned int num_meshes, ofs_meshes;
    //unsigned int num_vertexarrays, num_vertexes, ofs_vertexarrays;
    //unsigned int num_triangles, ofs_triangles, ofs_adjacency;
    //unsigned int num_joints, ofs_joints;
    //unsigned int num_poses, ofs_poses;
    //unsigned int num_anims, ofs_anims;
    //unsigned int num_frames, num_framechannels, ofs_frames, ofs_bounds;
    //unsigned int num_comment, ofs_comment;
    //unsigned int num_extensions, ofs_extensions;
    uint32_t version;
    uint32_t filesize;
    uint32_t flags;
    uint32_t num_text, ofs_text;
    uint32_t num_meshes, ofs_meshes;
    uint32_t num_vertexarrays, num_vertexes, ofs_vertexarrays;
    uint32_t num_triangles, ofs_triangles, ofs_adjacency;
    uint32_t num_joints, ofs_joints;
    uint32_t num_poses, ofs_poses;
    uint32_t num_anims, ofs_anims;
    uint32_t num_frames, num_framechannels, ofs_frames, ofs_bounds;
    uint32_t num_comment, ofs_comment;
    uint32_t num_extensions, ofs_extensions;
};

struct iqmmesh
{
    //unsigned int name;
    //unsigned int material;
    //unsigned int first_vertex, num_vertexes;
    //unsigned int first_triangle, num_triangles;
    uint32_t name;
    uint32_t material;
    uint32_t first_vertex, num_vertexes;
    uint32_t first_triangle, num_triangles;
};

enum
{
    IQM_POSITION     = 0,
    IQM_TEXCOORD     = 1,
    IQM_NORMAL       = 2,
    IQM_TANGENT      = 3,
    IQM_BLENDINDEXES = 4,
    IQM_BLENDWEIGHTS = 5,
    IQM_COLOR        = 6,
    IQM_CUSTOM       = 0x10
};

enum
{
    IQM_BYTE   = 0,
    IQM_UBYTE  = 1,
    IQM_SHORT  = 2,
    IQM_USHORT = 3,
    IQM_INT    = 4,
    IQM_UINT   = 5,
    IQM_HALF   = 6,
    IQM_FLOAT  = 7,
    IQM_DOUBLE = 8
};

struct iqmtriangle
{
    //unsigned int vertex[3];
    uint32_t vertex[3];
};

struct iqmadjacency
{
    //unsigned int triangle[3];
    uint32_t triangle[3];
};

struct iqmjointv1
{
    //unsigned int name;
    uint32_t name;
    int parent;
    float translate[3], rotate[3], scale[3];
};

struct iqmjoint
{
    //unsigned int name;
    uint32_t name;
    int parent;
    float translate[3], rotate[4], scale[3];
};

struct iqmposev1
{
    int parent;
    //unsigned int mask;
    uint32_t mask;
    float channeloffset[9];
    float channelscale[9];
};

struct iqmpose
{
    int parent;
    //unsigned int mask;
    uint32_t mask;
    float channeloffset[10];
    float channelscale[10];
};

struct iqmanim
{
    //unsigned int name;
    //unsigned int first_frame, num_frames;
    uint32_t name;
    uint32_t first_frame, num_frames;
    float framerate;
    //unsigned int flags;
    uint32_t flags;
};

enum
{
    IQM_LOOP = 1<<0
};

struct iqmvertexarray
{
    //unsigned int type;
    //unsigned int flags;
    //unsigned int format;
    //unsigned int size;
    //unsigned int offset;
    uint32_t type;
    uint32_t flags;
    uint32_t format;
    uint32_t size;
    uint32_t offset;
};

struct iqmbounds
{
    float bbmin[3], bbmax[3];
    float xyradius, radius;
};

struct iqmextension
{
    //unsigned int name;
    //unsigned int num_data, ofs_data;
    //unsigned int ofs_extensions; // pointer to next extension
    uint32_t name;
    uint32_t num_data, ofs_data;
    uint32_t ofs_extensions; // pointer to next extension
};

#endif

