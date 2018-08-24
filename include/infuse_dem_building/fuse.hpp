#ifndef __FUSE_HPP__
#define __FUSE_HPP__

#include <infuse_dem_building/common.hpp>
#include <gdalwrap/gdal.hpp>
#include <cassert>
#include <cstring>

namespace atlaas{

    class mapFuser{
        protected:

            cells_info_t            fusedMap;
            cells_info_t            roverMap;
            map_id_t                current;
            map_id_t                newTile;

            mutable gdalwrap::gdal  tile;
            std::string             atlaas_path; //Where to store fused maps

            int                     sw;
            int                     sh;
            size_t                  width;
            size_t                  height;
            uint64_t                time_base;

            float                   xOrigin;
            float                   yOrigin;
            float                   zOrigin;
            float                   zScale;
            float                   scale;

            bool                    isInit = false;
            float                   variance_threshold;
            cells_info_t            gndinter; // ground info for vertical/flat unknown state
            bool                    use_swap;


        public:

            mapFuser();
            ~mapFuser();
            void clean_up();


            void init(int mapWidth, int mapHeight);
            void tile_load(int sx, int sy /*, fusedMap, current */);
            void tile_save(int sx, int sy /*, fusedMap, current */) const;
            bool load_data(/*fusedMap*/);
            

            bool fuse(/*fusedMap,roverMap*/);
            void merge(cell_info_t& dst, const cell_info_t& src) const; 

            
            std::string tilepath(int x, int y) const 
            {
                std::ostringstream oss;
                oss << atlaas_path << "/atlaas." << x << "x" << y << ".tif";
                return oss.str();
            }

    };
}

#endif
