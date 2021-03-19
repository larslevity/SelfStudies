#include "image_browser.hpp"

using ScoredImage = std::tuple<std::string, float>;
using ImageRow = std::array<ScoredImage, 3>;

int main(){

    const ScoredImage img = std::make_tuple("data/000100.png", 0.77766123);
    const ImageRow row = {img, img, img};

    const std::vector<ImageRow> rows = {row, row, row, row, row};
    const std::string stylesheet = "style.css";
    const std::string title = "Test Browser";
    image_browser::CreateImageBrowser(title, stylesheet, rows);
    return 0;
}