#include <iostream>
#include <sstream>

#include "html_writer.hpp"
#include "fmt/core.h"

using fmt::print;

void html_writer::OpenDocument(){
    print("<!DOCTYPE html>\n");
    print("<html>\n");
}


void html_writer::CloseDocument(){
    print("</html>\n");
}

void html_writer::AddCSSStyle(const std::string& stylesheet){
    print("    <head>\n");
    print("        <link rel='stylesheet' type='text/css' href='{}' />\n", stylesheet);
    print("    </head>\n");
}


void html_writer::AddTitle(const std::string& title){
    print("    <title>{}</title>\n", title);
}


void html_writer::OpenBody(){
    print("    <body>\n");
}


void html_writer::CloseBody(){
    print("    </body>\n");
}


void html_writer::OpenRow(){
    print("        <div class='row'>\n");
}


void html_writer::CloseRow(){
    print("        </div>\n");
}


void html_writer::AddImage(const std::string& img_path, float score, bool highlight){
    std::string path = img_path.substr(0, img_path.find(".")); // Get path;
    std::string name = path.substr(path.rfind("/")+1); // Get name;
    std::string dir = path.substr(0, path.rfind("/")+1); // Get dir;
    std::string extension = img_path.substr(img_path.find(".")); // Get extension

    // std::cout << img_path << std::endl;
    // std::cout << dir << " -- " << name << " -- " << extension << std::endl;

    std::string str = "";
    if (highlight) {
        str = " style='border: 5px solid green;'";
    }

    print("            <div class='column'{}>\n", str);
    print("                 <h2>{}{}</h2>\n", name, extension);
    print("                 <img src='{}'/>\n", img_path);
    print("                 <p>score = {:0.2f}</p>\n", score);    
    print("            </div>\n", score);
}
