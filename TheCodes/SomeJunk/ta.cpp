#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile("sub.txt"); // 替换为你的输入文件名
    std::ofstream outputFile("output.txt"); // 替换为你的输出文件名

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "无法打开文件。" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        size_t firstTab = line.find('\t');
        size_t secondTab = line.find('\t', firstTab + 1);

        if (firstTab != std::string::npos && secondTab != std::string::npos) {
            std::string part1 = line.substr(0, firstTab);
            std::string part2 = line.substr(firstTab + 1, secondTab - firstTab - 1);
            std::string part3 = line.substr(secondTab + 1);

            outputFile << "(\"" << part1 << "\",\"" << part2 << "\"):" << part3 << std::endl;
        } else {
            outputFile << line << std::endl; // 如果行不符合格式，原样写入输出文件
        }
    }

    inputFile.close();
    outputFile.close();

    std::cout << "转换完成。" << std::endl;
    return 0;
}