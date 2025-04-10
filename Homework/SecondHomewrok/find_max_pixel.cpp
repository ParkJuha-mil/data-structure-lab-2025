#include <opencv2/opencv.hpp>
#include <iostream>

int getMaxPixelBrightness(const cv::Mat& image) {
    // �̹����� �� ��� ���� ó��
    if (image.empty()) {
        std::cerr << "�̹����� �ҷ��� �� �����ϴ�." << std::endl;
        return -1;
    }

    // �׷��̽����� �̹����� ��� �ٷ�, �÷��� ��� ��ȯ
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
    // �̹��� ���� ���
    std::string imagePath = "Lenna.png";  // ���� ��ġ�� Lenna.png�� �־�� ��

    // �̹��� �б�
    cv::Mat image = cv::imread(imagePath);

    int maxBrightness = getMaxPixelBrightness(image);
    if (maxBrightness != -1) {
        std::cout << maxBrightness << std::endl;  // ��� ����: 245
    }

    return 0;
}
