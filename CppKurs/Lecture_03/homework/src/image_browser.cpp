// @file      image_browser.cpp
// @author    Lars Schiller     [lars.schiller@posteo.de]
//
// Copyright (c) 2021 Lars Schiller, all rights reserved

/// Some Utility Name Types that will make the code more readable

#include "image_browser.hpp"
#include "html_writer.hpp"

// using ScoredImage = std::tuple<std::string, float>;
// using ImageRow = std::array<ScoredImage, 3>;

//(expression 1) ? expression 2 : expression 3
//If expression 1 evaluates to true, then expression 2 else expression 3.

void image_browser::AddFullRow(const ImageRow& row, bool first_row){

    html_writer::OpenRow();
    for (int i=0; i<3; i++){
        auto [img_path, score] = row[i];
        html_writer::AddImage(img_path, score, (i==0) ? first_row : false);
    }
    html_writer::CloseRow();
}


void image_browser::CreateImageBrowser(
        const std::string& title, const std::string& stylesheet, const std::vector<ImageRow>& rows){
    html_writer::OpenDocument();
    html_writer::AddTitle(title);
    html_writer::AddCSSStyle(stylesheet);
    html_writer::OpenBody();
    for(std::size_t i = 0; i < rows.size(); ++i) {
        image_browser::AddFullRow(rows[i], (i==0) ? true : false);
    }
    html_writer::CloseBody();
    html_writer::CloseDocument();
}


