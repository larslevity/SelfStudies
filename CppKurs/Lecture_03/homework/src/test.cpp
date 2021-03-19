#include "html_writer.hpp"

int main(){
    html_writer::OpenDocument();
    html_writer::AddTitle("Test Browser");
    html_writer::AddCSSStyle("style.css");
    html_writer::OpenBody();
    html_writer::OpenRow();
    html_writer::AddImage("data/000100.png", 0.888, true);
    html_writer::AddImage("data/000200.png", 0.668, false);
    html_writer::AddImage("data/000300.png", 0.558, false);
    html_writer::CloseRow();
    html_writer::CloseBody();
    html_writer::CloseDocument();
    return 0;
}