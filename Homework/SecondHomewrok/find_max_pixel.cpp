#include <opencv2/opencv.hpp>
#include <iostream>

int getMaxPixelBrightness(const cv::Mat& image) {
    // 이미지가 빈 경우 예외 처리
    if (image.empty()) {
        std::cerr << "이미지를 불러올 수 없습니다." << std::endl;
        return -1;
    }

    // 그레이스케일 이미지인 경우 바로, 컬러인 경우 변환
    cv::Mat gray;
    if (image.channels() == 1) {
        gray = image;
    }
    else {
        cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    }

    double minVal, maxVal;
    cv::minMaxLoc(gray, &minVal, &maxVal);

    return static_cast<int>(maxVal);
}

int main() {
    // 이미지 파일 경로
    std::string imagePath = "Lenna.png";  // 실행 위치에 Lenna.png가 있어야 함

    // 이미지 읽기
    cv::Mat image = cv::imread(imagePath);

    int maxBrightness = getMaxPixelBrightness(image);
    if (maxBrightness != -1) {
        std::cout << maxBrightness << std::endl;  // 출력 예시: 245
    }

    return 0;
}
