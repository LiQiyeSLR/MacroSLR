#include "fopencv.h"




fopencv::fopencv() {

}

fopencv::~fopencv() {

}

cv::Vec3b fopencv::getPixel(cv::Mat img, int x, int y) {
    return img.at<cv::Vec3b>(y, x);
}

cv::Mat fopencv::CreateMat(std::string path) {
    cv::Mat img = cv::imread(path, cv::IMREAD_REDUCED_COLOR_2);
    return img;
}
void fopencv::showImg(std::string path) {
    cv::Mat img = CreateMat(path);
    imshow("img", img);
    int x = (1920 - img.cols) / 5.4;
    int y = (1080 - img.rows) / 6;
    cv::moveWindow("img", x, y);
    cv::waitKey(0);
}

cv::Mat fopencv::DetectContours(cv::Mat img) {
    cv::Mat imgBlur, imgCanny, imgDil, imgErode, imgRange;
    cv::Scalar lower(50, 0, 100);
    cv::Scalar upper(100, 255, 150);
    inRange(img, lower, upper, imgRange);
    GaussianBlur(imgRange, imgBlur, cv::Size(0, 0), 1, 0);
    Canny(imgBlur, imgCanny, 65, 75);
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    dilate(imgCanny, imgDil, kernel);
    return imgDil;
}

void fopencv::getContours(std::string pathImg) { //à revoir
    cv::Mat img = CreateMat(pathImg);
    cv::Mat imgDil = DetectContours(img);
    std::vector<std::vector<cv::Point>>contours;
    std::vector<cv::Vec4i>hierarchy;
    findContours(imgDil, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    drawContours(img, contours, -1, cv::Scalar(255, 0, 255), 2);
    imshow("img", img);
}

void fopencv::showImgtest(std::string path) {
    int hmin = 0, smin = 0, vmin = 0;
    int hmax = 255, smax = 255, vmax = 255;
    cv::Mat img = cv::imread(path, cv::IMREAD_REDUCED_COLOR_2);

    cv::Mat imgHSV, mask;
    cvtColor(img, imgHSV, cv::COLOR_BGR2HSV);
    cv::namedWindow("Track", (640, 200));
    cv::createTrackbar("Hue min", "Track", &hmin, 255);
    cv::createTrackbar("Hue max", "Track", &hmax, 255);
    cv::createTrackbar("sat min", "Track", &smin, 255);
    cv::createTrackbar("sat max", "Track", &smax, 255);
    cv::createTrackbar("Val min", "Track", &vmin, 255);
    cv::createTrackbar("Val max", "Track", &vmax, 255);

    while (true) {
        cv::Scalar lower(0, 0, 213);
        cv::Scalar upper(255, 179, 255);
        inRange(imgHSV, lower, upper, mask);
        imshow("Image", img);
        cv::moveWindow("Image", 0, 0);
        imshow("imagemod1", imgHSV);
        cv::moveWindow("imagemod1", 0, 400);
        imshow("imagemod2", mask);
        cv::moveWindow("imagemod2", 700, 0);
        cv::moveWindow("Track", 700, 400);
        cv::waitKey(1);
    }
}


bool fopencv::findImage(std::string tempimg,std::string backgroundimage, int&x, int&y) {
    cv::Mat templateImg = cv::imread(tempimg, cv::IMREAD_COLOR);

    cv::Mat background = cv::imread(backgroundimage, cv::IMREAD_COLOR);
    double precision = 0.9;
    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    while (true) {
        cv::Mat result;
        cv::matchTemplate(background, templateImg, result, cv::TM_CCOEFF_NORMED);

        minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
        if (maxVal >= precision) {
            cv::Point topLeft = maxLoc;
            cv::Point bottomRight(topLeft.x + templateImg.cols, topLeft.y + templateImg.rows);
            x = (topLeft.x + bottomRight.x) / 2;
            y = (topLeft.y + bottomRight.y) / 2;
            std::cout << "X: " << x;
            std::cout << " Y: " << y;
            std::cout << "found maxVal: "<<maxVal<<" " << tempimg << std::endl;
            return true;
        }
        precision -= 0.08;
        if (precision < 0.66) {
            std::cout << "not found maxVal: "<<maxVal<<" " << tempimg << std::endl;;
            return false;
        }
    }
}

bool fopencv::findMultipleImage(std::string tempimg, std::vector<Coords>&listcoords) {
    listcoords.clear();
    cv::Mat templateImg = cv::imread(tempimg, cv::IMREAD_COLOR);
    cv::Mat background = cv::imread("./img/screenshot.png", cv::IMREAD_COLOR);
    double precision = 0.9;
    double minVal, maxVal;
    cv::Point minLoc, maxLoc;
    Coords tab;
    while (true) {
        cv::Mat result;
        bool present=false;
        cv::matchTemplate(background, templateImg, result, cv::TM_CCOEFF_NORMED);

        minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
        if (maxVal >= precision) {
            
            cv::Point topLeft = maxLoc;
            cv::Point bottomRight(topLeft.x + templateImg.cols, topLeft.y + templateImg.rows);
            tab.x=(topLeft.x + bottomRight.x) / 2;
            tab.y=(topLeft.y + bottomRight.y) / 2;
            std::cout << "X: " << tab.x;
            std::cout << " Y: " << tab.y;
            for (int i = 0; i < listcoords.size(); ++i) {
                if (listcoords[i].x == tab.x && listcoords[i].y == tab.y)present = true;
            }
            if(!present)listcoords.push_back(tab);
            std::cout << "found maxVal: " << maxVal << " " << tempimg << std::endl;
        }


        precision -= 0.06;
        if (precision < 0.68) {
            std::cout << "not found maxVal: " << maxVal << " " << tempimg << std::endl;;
            if (!listcoords.empty())return true;
            else {
                return false;
            }
        }
    }
}



bool fopencv::checkImage(std::string tempimg) {
    cv::Mat templateImg = cv::imread(tempimg, cv::IMREAD_COLOR);
    cv::Mat background = cv::imread("./img/screenshot.png", cv::IMREAD_COLOR);
    double precision = 0.7;
    while (true) {
        cv::Mat result;
        cv::matchTemplate(background, templateImg, result, cv::TM_CCOEFF_NORMED);
        double minVal, maxVal;
        cv::Point minLoc, maxLoc;
        minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
        if (maxVal >= precision) {
            cv::Point topLeft = maxLoc;
            cv::Point bottomRight(topLeft.x + templateImg.cols, topLeft.y + templateImg.rows);
            rectangle(background, topLeft, bottomRight, cv::Scalar(0, 255, 0), 2);
            std::cout << "found";
            return true;
        }
        precision -= 0.05;
        if (precision < 0.5) {
            std::cout << "not found" << std::endl;
            return false;
        }
    }
}


