#include "svg.h"

int main() {
  SVG svg;

  const char* colors[] = {"#FF8383", "#FFF574", "#A19AD3", "#A1D6CB"};
  int num_color = 4;

  int num_row = 8;
  int num_col = 4;
  int dx = 80;
  int dy = 40;

  for (int irow = 0; irow < num_row; ++irow) {
    int y = irow * dy;
    for (int icol = 0; icol < num_col; ++icol) {
      int x = icol * dx;
      int idx = icol + irow * num_col;

      std::string text = std::string("T") + std::to_string(icol);

      svg.addRect()
          .x(x)
          .y(y)
          .width(dx)
          .height(dy)
          .stroke("black")
          .stroke_width(2)
          .fill(colors[idx % num_color]);
      svg.addText()
          .x(x + dx / 2)
          .y(y + dy / 2)
          .font_size(dy - 10)
          .alignment_baseline("central")
          .text_anchor("middle")
          .text(text);
    }
  }

  svg.Write("a.svg");

  return 0;
}
