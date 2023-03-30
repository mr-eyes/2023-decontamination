#include <iostream>
#include <cstdint>
#include <chrono>
#include <ctime>
#include<omp.h>
#include <queue>
#include <glob.h>
#include "parallel_hashmap/phmap.h"
#include "parallel_hashmap/phmap_dump.h"
#include <tuple>
#include <string>
#include <algorithm>

typedef std::chrono::high_resolution_clock Time;
using phmap::flat_hash_map;
using namespace std;

using BINS_PHMAP = phmap::parallel_flat_hash_map<std::string, phmap::flat_hash_set<uint64_t>,
    phmap::priv::hash_default_hash<std::string>,
    phmap::priv::hash_default_eq<std::string>,
    std::allocator<std::pair<const std::string, phmap::flat_hash_set<uint64_t>>>,
    1,
    std::mutex>;


using BINS_KMER_COUNT = phmap::parallel_flat_hash_map<std::string, uint32_t,
    phmap::priv::hash_default_hash<std::string>,
    phmap::priv::hash_default_eq<std::string>,
    std::allocator<std::pair<const std::string, uint32_t>>,
    1,
    std::mutex>;


using int_int_map = phmap::parallel_flat_hash_map<uint32_t, uint32_t, std::hash<uint32_t>, std::equal_to<uint32_t>, std::allocator<std::pair<const uint32_t, uint32_t>>, 1>;
using int_vec_map = phmap::parallel_flat_hash_map<uint32_t, vector<uint32_t>, std::hash<uint32_t>, std::equal_to<uint32_t>, std::allocator<std::pair<const uint32_t, vector<uint32_t>>>, 1>;


uint64_t to_uint64_t(std::string const& value);

struct file_info {
    string path;
    string prefix;
    string extension;
    string base_name;
};


vector<file_info> file_fetcher(const std::string& pattern);



vector<tuple<uint64_t, uint64_t>> splitted_ranges(uint64_t max_hash, int cores);



template <typename T>
void ascending(T& dFirst, T& dSecond)
{
    if (dFirst > dSecond)
        std::swap(dFirst, dSecond);
}


void load_all_bins(string bins_dir, BINS_PHMAP* bin_to_hashes, int cores);


string create_dir(string output_file, int serial);

inline string time_diff(std::chrono::high_resolution_clock::time_point& t1);





std::pair<string, std::vector<uint32_t>> classify_and_match_read_kmers(const std::vector<uint32_t>& genome_ids, double coverage_threshold = 0.1, double ratio_threshold = 2.0);
