#include "svg.h"

#include <fstream>
#include <iostream>

// Rect implementation
Rect::Rect() : x_(0), y_(0), width_(0), height_(0), stroke_width_(1) {}

Rect::~Rect() {}

Rect& Rect::x(double x) {
  x_ = x;
  return *this;
}

Rect& Rect::y(double y) {
  y_ = y;
  return *this;
}

Rect& Rect::width(double width) {
  width_ = width;
  return *this;
}

Rect& Rect::height(double height) {
  height_ = height;
  return *this;
}

Rect& Rect::fill(const std::string& color) {
  fill_color_ = color;
  return *this;
}

Rect& Rect::stroke(const std::string& color) {
  stroke_color_ = color;
  return *this;
}

Rect& Rect::stroke_width(double width) {
  stroke_width_ = width;
  return *this;
}

std::string Rect::emit() const {
  return "<rect x=\"" + std::to_string(x_) + "\" y=\"" + std::to_string(y_) +
         "\" width=\"" + std::to_string(width_) + "\" height=\"" +
         std::to_string(height_) + "\" fill=\"" + fill_color_ + "\" stroke=\"" +
         stroke_color_ + "\" stroke-width=\"" + std::to_string(stroke_width_) +
         "\" />";
}

Text::Text()
    : x_(0),
      y_(0),
      font_size_(12),
      text_anchor_("start"),
      alignment_baseline_("baseline") {}

Text::~Text() {}

Text& Text::x(double x) {
  x_ = x;
  return *this;
}

Text& Text::y(double y) {
  y_ = y;
  return *this;
}

Text& Text::text(const std::string& text) {
  text_ = text;
  return *this;
}

Text& Text::font_size(double font_size) {
  font_size_ = font_size;
  return *this;
}

Text& Text::text_anchor(const std::string& anchor) {
  text_anchor_ = anchor;
  return *this;
}

Text& Text::alignment_baseline(const std::string& baseline) {
  alignment_baseline_ = baseline;
  return *this;
}

std::string Text::emit() const {
  return "<text x=\"" + std::to_string(x_) + "\" y=\"" + std::to_string(y_) +
         "\" font-size=\"" + std::to_string(font_size_) + "\" fill=\"black\" " +
         "text-anchor=\"" + text_anchor_ + "\" alignment-baseline=\"" +
         alignment_baseline_ + "\">" + text_ + "</text>";
}

// SVG implementation
SVG::SVG() {}

SVG::~SVG() {}

Rect& SVG::addRect() {
  elements_.emplace_back(std::make_shared<Rect>());
  return *std::dynamic_pointer_cast<Rect>(elements_.back());
}

Text& SVG::addText() {
  elements_.emplace_back(std::make_shared<Text>());
  return *std::dynamic_pointer_cast<Text>(elements_.back());
}

bool SVG::Write(const std::string& file) {
  std::ofstream ofs(file);
  if (!ofs.is_open()) return false;

  ofs << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">"
      << std::endl;
  for (const auto& element : elements_) {
    ofs << element->emit() << std::endl;
  }
  ofs << "</svg>" << std::endl;

  return true;
}
