#include<iostream>
#include<filesystem>
#include<fstream>
using namespace std;

class NNGMJ {
private:
    char ZD[62] = { '5','y','z','A','F','8','H','d','e','T','U','Y','f','v','i','V','W','X','j','J','K','L','9','l','B','g','h','3','O','P','m','I','E','4','Z','p','k','s','N','G','o','0','1','Q','b','R','t','u','M','q','7','w','x','D','r','a','c','n','C','6','S','2' };
    short MY[5];
public:
    struct MYANDDATA {
        string Data;
        short MY[5];
    };
    short whereZD(char b) {
        for (short i = 0; i < 62; i++) {
            if (ZD[i] == b)return i;
        }
    }
    MYANDDATA Nngmj(string data, short m1 = 5, short m2 = 5, short m3 = 5, short m4 = 5, short m5 = 5) {
        MYANDDATA sdata;
        sdata.MY[0] = m1;
        sdata.MY[1] = m2;
        sdata.MY[2] = m3;
        sdata.MY[3] = m4;
        sdata.MY[4] = m5;
        for (char a : data)
        {
            switch (a)
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                sdata.Data += ZD[((m5 * 2401) + (m4 * 343) + (m3 * 49) + (m2 * 7) + m1 + whereZD(a)) % 62];
                m1++;
                break;
            default:
                sdata.Data += '0';
                m1++;
                break;
            }
            if (m1 == 7) {
                m1 = 0;
                m2++;
            }
            if (m2 == 7) {
                m2 = 0;
                m3++;
            }
            if (m3 == 7) {
                m3 = 0;
                m4++;
            }
            if (m4 == 7) {
                m4 = 0;
                m5++;
            }
            if (m5 == 7) {
                m5 = 0;
            }
        }
        return sdata;
    }
    std::string Decrypt(MYANDDATA Data) {
        const std::string& encryptedData = Data.Data;
        short m1 = Data.MY[0];
        short m2 = Data.MY[1];
        short m3 = Data.MY[2];
        short m4 = Data.MY[3];
        short m5 = Data.MY[4];
        std::string originalData;
        for (char encryptedChar : encryptedData) {
            // 计算加密字符在 ZD 数组中的索引
            short encryptedIndex = whereZD(encryptedChar);
            if (encryptedIndex != -1) {
                // 逆向计算原始字符的索引
                short originalIndex = ((encryptedIndex - ((m5 * 2401) + (m4 * 343) + (m3 * 49) + (m2 * 7) + m1) + 62 * 100) % 62);
                if (originalIndex < 0)originalIndex += 62;
                originalData += ZD[originalIndex];
            }
            else {
                originalData += '0'; // 处理无效字符
            }
            // 更新状态
            m1++;
            if (m1 == 7) {
                m1 = 0;
                m2++;
            }
            if (m2 == 7) {
                m2 = 0;
                m3++;
            }
            if (m3 == 7) {
                m3 = 0;
                m4++;
            }
            if (m4 == 7) {
                m4 = 0;
                m5++;
            }
            if (m5 == 7) {
                m5 = 0;
            }
        }
        return originalData;
    }
};

string duru(string whereFile) {
    filesystem::path filePath = whereFile;

    // 检查文件是否存在
    if (!filesystem::exists(filePath)) {
        std::cerr << "文件 " << filePath << " 不存在！" << std::endl;
        return {};
    }

    // 检查是否为普通文件
    if (!filesystem::is_regular_file(filePath)) {
        std::cerr << filePath << " 不是一个普通文件！" << std::endl;
        return {};
    }

    // 打开文件进行读取
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cerr << "无法打开文件 " << filePath << "！" << std::endl;
        return {};
    }
    string data;
    std::string line;
    // 逐行读取文件内容
    while (std::getline(inputFile, line)) {
        data += line;
    }

    // 关闭文件
    inputFile.close();
    return data;
}

void xieru(filesystem::path filePath, string data) {
    try {
        // 检查文件所在目录是否存在，如果不存在则创建
        filesystem::create_directories(filePath.parent_path());

        // 打开文件进行写入，如果文件不存在则创建，如果存在则截断内容
        std::ofstream outputFile(filePath);

        // 检查文件是否成功打开
        if (!outputFile.is_open()) {
            std::cerr << "无法打开文件 " << filePath << " 进行写入！" << std::endl;
            return;
        }

        // 写入一些示例内容
        outputFile << data;

        // 关闭文件
        outputFile.close();

        std::cout << "文件写入成功，文件路径为: " << filePath << std::endl;
    }
    catch (const filesystem::filesystem_error& e) {
        std::cerr << "文件系统操作出错: " << e.what() << std::endl;
        return;
    }

    return;
}



int main() {
    string whereFile;
    cin >> whereFile;
    string data = duru(whereFile);
    short arrMY[5] = { 0,0,0,0,0 };
    cin >> arrMY[0] >> arrMY[1] >> arrMY[2] >> arrMY[3] >> arrMY[4];
    NNGMJ nngmj;
    NNGMJ::MYANDDATA jmdata = nngmj.Nngmj(data, arrMY[0], arrMY[1], arrMY[2], arrMY[3], arrMY[4]);
    cout << jmdata.Data << endl;
    string jMdata = nngmj.Decrypt(jmdata);
    cout << jMdata << endl;
    return 0;
}

