#include "ocr.h"

ocr::ocr() {
	api = new tesseract::TessBaseAPI();
}
bool ocr::detectText(string targetWord,int x,int y) {
    im = imread(imPath, IMREAD_COLOR);
    api->Init(NULL, "eng", tesseract::OEM_TESSERACT_LSTM_COMBINED);
    api->SetPageSegMode(tesseract::PSM_SINGLE_BLOCK);
    api->SetVariable("tessedit_char_whitelist", "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789"); // Set character whitelist for improved accuracy
    cvtColor(im, im, cv::COLOR_BGR2GRAY);
    namedWindow("test", 0);
    api->SetImage(im.data, im.cols, im.rows, 1, im.step);
    outText = api->GetUTF8Text();
    // Specify the portion of the word you want to detect
    std::string lowercaseTargetWord = targetWord;
    std::transform(lowercaseTargetWord.begin(), lowercaseTargetWord.end(), lowercaseTargetWord.begin(), ::tolower);
    tesseract::PageIteratorLevel myLevel = tesseract::RIL_WORD;
    tesseract::ResultIterator* resultIterator = api->GetIterator();
    if (resultIterator != nullptr) {
        int x1, y1, x2, y2;  // Define the variables for coordinates
        resultIterator->Begin();
        do {
            std::string curText = resultIterator->GetUTF8Text(myLevel);
            std::string lowercaseCurText = curText;
            std::transform(lowercaseCurText.begin(), lowercaseCurText.end(), lowercaseCurText.begin(), ::tolower);
            if (resultIterator->BoundingBox(myLevel, &x1, &y1, &x2, &y2)) {
                // Perform your desired operations here with the bounding box and text
                if (lowercaseCurText.find(lowercaseTargetWord) != std::string::npos) {
                    std::cout << "Found the word portion '" << targetWord << "': "
                        << "x1=" << x1 << ", y1=" << y1 << ", x2=" << x2 << ", y2=" << y2 << std::endl;
                    x = (x1 + x2) / 2;
                    y = (y1 + y2) / 2;
                    return true;
                }
                std::cout << lowercaseCurText;
            }
        } while (resultIterator->Next(myLevel));

    } 
    return false;
}
ocr::~ocr() {
	delete api;
}