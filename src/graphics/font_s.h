#pragma once 

#include "defines.h"
#include "graphics/texture.h"

#include <ft2build.h>
#include <freetype/freetype.h>
#include <glm/glm.hpp>

#include <string>

// Glyph
/////////////////////////////////////////////////////////////////////////////////
struct Glyph {
  i8 unicode;
  Texture* texture;

  glm::ivec2 size;
  glm::ivec2 bearing;
  
  i32 advance_x, kern, left_side_bearing;

  struct Bounds {
    i32 left, right, top, bottom;
  };
  Bounds bounds;
};
/////////////////////////////////////////////////////////////////////////////////

// Font
/////////////////////////////////////////////////////////////////////////////////
struct Font {
  FT_Library lib; 
  FT_Face face;

  f32 ascent, descent, line_gap;
  u32 glyphs_count;
  Glyph* glyphs;
};
/////////////////////////////////////////////////////////////////////////////////

// Public functions
/////////////////////////////////////////////////////////////////////////////////
Font* font_load(const std::string& path, const f32 size);
void font_unload(Font* font);
i32 font_get_glyph_index(const Font* font, i8 codepoint);
/////////////////////////////////////////////////////////////////////////////////