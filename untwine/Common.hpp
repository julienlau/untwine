#pragma once

#include <stdint.h>
#include <array>
#include <string>
#include <vector>

#include <pdal/SpatialReference.hpp>
#include <pdal/util/Bounds.hpp>

#include "FileDimInfo.hpp"

namespace untwine
{

// Number of cells into which points are put for each octree voxel.
const int CellCount = 128;

using PointCount = uint64_t;
using StringList = std::vector<std::string>;

void fatal(const std::string& err);

struct Options
{
    std::string outputName;
    bool singleFile;
    StringList inputFiles;
    std::string tempDir;
    bool cleanTempDir;
    bool doCube;
    size_t fileLimit;
    int level;
    int progressFd;
    StringList dimNames;
    bool stats;
    std::string a_srs;
    bool metadata;
};

struct BaseInfo
{
public:
    BaseInfo()
    {};

    Options opts;
    pdal::BOX3D bounds;
    pdal::BOX3D trueBounds;
    size_t pointSize;
    std::string outputFile;
    DimInfoList dimInfo;
    pdal::SpatialReference srs;
    int pointFormatId;

    using d3 = std::array<double, 3>;
    d3 scale { -1.0, -1.0, -1.0 };
    d3 offset {};
};

const std::string MetadataFilename {"info2.txt"};

} // namespace untwine
