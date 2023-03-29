cmake_minimum_required (VERSION 3.4)
project (kDecontaminer C CXX)
set(default_build_type "Release")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++17 -fPIC -lgomp -lrt -fopenmp -W -Wall -pedantic -O3 -Ofast -march=native")

add_subdirectory(lib/kmerDecoder)
add_subdirectory(lib/zstr)

set(PHMAP_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/lib/kmerDecoder/lib/parallel-hashmap")
include_directories("${PHMAP_INCLUDE_DIRS}")

include_directories(includes)


# add_executable (peReadsStats reads_stats.cpp src/kseqReader.cpp)
# target_link_libraries (peReadsStats kProcessor z)
# target_include_directories(peReadsStats INTERFACE ${kProcessor_INCLUDE_PATH})

# add_executable (analyzeIdx analyze_index.cpp)
# target_link_libraries (analyzeIdx kProcessor)
# target_include_directories(analyzeIdx INTERFACE ${kProcessor_INCLUDE_PATH})

# add_executable (cDBG_partitioner cDBG_partitioner.cpp)
# target_link_libraries (cDBG_partitioner kProcessor z)
# target_include_directories(cDBG_partitioner INTERFACE ${kProcessor_INCLUDE_PATH})

# add_executable (commonKmers commonKmers.cpp)
# target_link_libraries (commonKmers kProcessor z)
# target_include_directories(commonKmers INTERFACE ${kProcessor_INCLUDE_PATH})

# add_executable (fastq_partitioner fastq_partitioner.cpp)
# target_link_libraries (fastq_partitioner kProcessor z)
# target_include_directories(fastq_partitioner INTERFACE ${kProcessor_INCLUDE_PATH})

#add_executable (testKseq test_kseq.cpp)
#target_link_libraries (testKseq z)



# genesIndexing executable (Have an issue after some time in the execution)
#add_executable (genesIndexing genes_indexing.cpp)
#target_link_libraries (genesIndexing kProcessor pthread z)
#target_include_directories(genesIndexing INTERFACE ${kProcessor_INCLUDE_PATH})


# 1) Convert the reference to bin
add_executable(refToBin 1_ref_to_bin.cpp)
target_link_libraries(refToBin kmerDecoder pthread z zstr::zstr)