#include "svgcpp.h"

int main() {
  svgcpp::SVG svg;

  const char* colors[] = {"#FF8383", "#FFF574", "#A19AD3", "#A1D6CB", "	#c1d08a", "#7cb46b", "#b0c1b3", "#96845a"};
  int num_color = 8;

  int num_row = 8;
  int num_col = 8;

  int fx = 100;
  int fy = 100;
  int dx = 160;
  int dy = 20;

  int font_size = std::max(20, dy - 16);

  // original
  for (int irow = 0; irow < num_row; ++irow) {
    int y = fy + irow * dy;
    for (int icol = 0; icol < num_col; ++icol) {
      int x = fx + icol * dx;
      int idx = icol + irow * num_col;

      int ibank = idx % 8;
      std::string text = std::string("B") + std::to_string(ibank);

      svg.AddRect()
          .x(x)
          .y(y)
          .width(dx)
          .height(dy)
          .stroke("black")
          .stroke_width(2)
          .fill(colors[idx % num_color]);
      svg.AddText()
          .x(x + dx / 2)
          .y(y + dy / 2)
          .font_size(font_size)
          .alignment_baseline("central")
          .text_anchor("middle")
          .text(text);
    }
  }

  fy += (num_row + 2) * dy;
  // swizzled
  for (int irow = 0; irow < num_row; ++irow) {
    int y = fy + irow * dy;
    for (int icol = 0; icol < num_col; ++icol) {
      int icolx = icol ^ irow;
      int x = fx + icolx * dx;

      int idx = icol + irow * num_col;
      int ibank = idx % 8;

      std::string text = std::string("B") + std::to_string(ibank);

      svg.AddRect()
          .x(x)
          .y(y)
          .width(dx)
          .height(dy)
          .stroke("black")
          .stroke_width(2)
          .fill(colors[idx % num_color]);
      svg.AddText()
          .x(x + dx / 2)
          .y(y + dy / 2)
          .font_size(font_size)
          .alignment_baseline("central")
          .text_anchor("middle")
          .text(text);
    }
  }

  svg.Write("a.svg");

  return 0;
}
