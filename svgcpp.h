#ifndef SVGCPP_H_
#define SVGCPP_H_

#include <memory>
#include <string>
#include <vector>

namespace svgcpp {

class Element {
 public:
  Element() {}
  virtual ~Element() {}

  virtual std::string emit() const = 0;
};

class Rect : public Element {
 public:
  Rect();
  virtual ~Rect();

  Rect& x(double x);
  Rect& y(double y);
  Rect& width(double width);
  Rect& height(double height);
  Rect& fill(const std::string& color);
  Rect& stroke(const std::string& color);
  Rect& stroke_width(double width);

  std::string emit() const override;

 private:
  double x_;
  double y_;
  double width_;
  double height_;
  std::string fill_color_;
  std::string stroke_color_;
  double stroke_width_;
};

class Text : public Element {
 public:
  Text();
  virtual ~Text();

  Text& x(double x);
  Text& y(double y);
  Text& text(const std::string& text);
  Text& font_size(double font_size);
  Text& text_anchor(const std::string& anchor);
  Text& alignment_baseline(const std::string& baseline);

  std::string emit() const override;

 private:
  double x_;
  double y_;
  std::string text_;
  double font_size_;
  std::string text_anchor_;
  std::string alignment_baseline_;
};

class SVG {
 public:
  SVG();
  virtual ~SVG();

  Rect& AddRect();
  Text& AddText();

  bool Write(const std::string& file);

 private:
  std::vector<std::shared_ptr<Element>> elements_;
};

}  // namespace svgcpp

#endif  // SVGCPP_H_
