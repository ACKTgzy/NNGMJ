#include<iostream>
#include<filesystem>
#include<fstream>
#include<vector>
using namespace std;

class NNGMJ {
    friend class ShanLan;
private:
    short LS = 95;
	short zzsize = 10;
    char ZD[95] = { '5','y','+','8','H','=','z','F',',','A','i','E','4','Z','p','_','V','W',' ','X','k','s','b','D','r','C','6','S','2',';','"','a','c','n','\'','{','o','0','1','Q','(',')','}','[','R','t','u','M','q','7','w','x',']','\\','|','~','`','!','@','#','J','K','L','9','l','B','g','h','3','O','P','m','$','%','^','&','*','N','G','-','j','I','<','U','>','T','Y','/','?',':','d','.','e','f','v' };
    short MY[5];
public:
    struct MYANDDATA {
        std::string Data;
        short MY[5];
    };
    short whereZD(char b) {
        for (short i = 0; i < LS; i++) {
            if (ZD[i] == b)return i;
        }
        cout << "error" << endl;
        exit(-1);
    }
    MYANDDATA Nngmj(std::string data, short m1 = 5, short m2 = 5, short m3 = 5, short m4 = 5, short m5 = 5) {
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
            case '.':
            case ',':
            case '<':
            case '>':
            case '/':
            case '?':
            case ';':
            case ':':
            case '\'':
            case '"':
            case '[':
            case ']':
            case '{':
            case '}':
            case '\\':
            case '|':
            case '~':
            case '`':
            case '!':
            case '@':
            case '#':
            case '$':
            case '%':
            case '^':
            case '&':
            case '*':
            case '(':
            case ')':
            case '_':
            case '-':
            case '+':
            case '=':
            case ' ':
                sdata.Data += ZD[((m5 * zzsize * zzsize * zzsize * zzsize) + (m4 * zzsize * zzsize * zzsize) + (m3 * zzsize * zzsize) + (m2 * zzsize) + m1 + whereZD(a)) % LS];
                m1++;
                break;
            default:
                sdata.Data += '0';
                m1++;
                break;
            }
            if (m1 == zzsize) {
                m1 = 0;
                m2++;
            }
            if (m2 == zzsize) {
                m2 = 0;
                m3++;
            }
            if (m3 == zzsize) {
                m3 = 0;
                m4++;
            }
            if (m4 == zzsize) {
                m4 = 0;
                m5++;
            }
            if (m5 == zzsize) {
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
                short originalIndex = ((encryptedIndex - ((m5 * zzsize * zzsize * zzsize * zzsize) + (m4 * zzsize * zzsize * zzsize) + (m3 * zzsize * zzsize) + (m2 * zzsize) + m1) + LS * 100) % LS);
                if (originalIndex < 0)originalIndex += LS;
                originalData += ZD[originalIndex];
            }
            else {
                originalData += '0'; // 处理无效字符
            }
            // 更新状态
            m1++;
            if (m1 == zzsize) {
                m1 = 0;
                m2++;
            }
            if (m2 == zzsize) {
                m2 = 0;
                m3++;
            }
            if (m3 == zzsize) {
                m3 = 0;
                m4++;
            }
            if (m4 == zzsize) {
                m4 = 0;
                m5++;
            }
            if (m5 == zzsize) {
                m5 = 0;
            }
        }
        return originalData;
    }
};

class ShanLan
{
private:
    string encryptRailFence(string text, int key) {
        if (key == 1) return text;

        vector<string> rails(key);
        int direction = -1;
        int row = 0;

        for (char c : text) {
            rails[row] += c;
            if (row == 0 || row == key - 1) {
                direction = -direction;
            }
            row += direction;
        }

        string encrypted;
        for (const string& rail : rails) {
            encrypted += rail;
        }

        return encrypted;
    }
    string decryptRailFence(string encrypted, int key) {
        if (key == 1) return encrypted;

        vector<string> rails(key);
        vector<int> rowLengths(key, 0);
        int direction = -1;
        int row = 0;

        // 计算每一行的长度
        for (char c : encrypted) {
            rowLengths[row]++;
            if (row == 0 || row == key - 1) {
                direction = -direction;
            }
            row += direction;
        }

        // 将密文按行分割
        int index = 0;
        for (int i = 0; i < key; i++) {
            rails[i] = encrypted.substr(index, rowLengths[i]);
            index += rowLengths[i];
        }

        // 重建明文
        string decrypted;
        direction = -1;
        row = 0;
        vector<int> currentPos(key, 0);

        for (char c : encrypted) {
            decrypted += rails[row][currentPos[row]++];
            if (row == 0 || row == key - 1) {
                direction = -direction;
            }
            row += direction;
        }

        return decrypted;
    }

public:
    std::string shanlan(std::string input,bool mood) {
        string output;
        NNGMJ nngmj;
        int key = 0;
        key = nngmj.whereZD(input[0]);
        if ((key == 0) || (key == 1))key = 2;
        if (mood == true)output = encryptRailFence(input, key);
		if (mood == false)output = decryptRailFence(input, key);
        return output;
    }
};


class BASE64 {
    friend class NNGMJ;
private:
    const std::string base64bin = "ASDFGHJKLZXCVBNMQWERTYUIOPasdfghjklzxcvbnmqwertyuiop1234567890+/";
    std::string base64_encode(const std::string& input) {
        std::string output;
        short i = 0;
        short j = 0;
        unsigned char carry_3[3];
        unsigned char carry_4[4];
        for (const char c : input) {
            carry_3[i++] = c;
            if (i == 3) {
                carry_4[0] = (carry_3[0] & 0xfc) >> 2;
                carry_4[1] = ((carry_3[0] & 0x03) << 4) + ((carry_3[1] & 0xf0) >> 4);
                carry_4[2] = ((carry_3[1] & 0x0f) << 2) + ((carry_3[2] & 0xc0) >> 6);
                carry_4[3] = (carry_3[2] & 0x3f);
                for (i = 0; i < 4; i++)output += base64bin[carry_4[i]];
                i = 0;
            }
        }
        if (i > 0) {
            for (j = i; j < 3; j++) {
                carry_3[j] = '\0';
                carry_4[0] = (carry_3[0] & 0xfc) >> 2;
                carry_4[1] = ((carry_3[0] & 0x03) << 4) + ((carry_3[1] & 0xf0) >> 4);
                carry_4[2] = ((carry_3[1] & 0x0f) << 2) + ((carry_3[2] & 0xc0) >> 6);
                carry_4[3] = (carry_3[2] & 0x3f);
                for (j = 0; j < (i + 1); j++)output += base64bin[carry_4[j]];
                while ((i++ < 3))output += '=';
            }
        }
        return output;
    }
    std::string base64_decode(const std::string& input) {
        std::string output;
        std::vector<unsigned char> vec(input.begin(), input.end());
        std::vector<unsigned char> decoded;

        // 先将每个base64字符转换为对应的6位值
        for (char c : input) {
            if (c == '=') break; // 填充字符，停止处理
            size_t pos = base64bin.find(c);
            if (pos != std::string::npos) {
                decoded.push_back(pos);
            }
            else {
                // 非法字符，忽略或处理错误
                std::cerr << "error:" << c << " isn't base64 char" << std::endl;
                exit(-1);
            }
        }

        // 处理解码逻辑
        for (size_t i = 0; i < decoded.size(); i += 4) {
            unsigned char b1 = decoded[i];
            unsigned char b2 = (i + 1 < decoded.size()) ? decoded[i + 1] : 0;
            unsigned char b3 = (i + 2 < decoded.size()) ? decoded[i + 2] : 0;
            unsigned char b4 = (i + 3 < decoded.size()) ? decoded[i + 3] : 0;

            unsigned char c1 = (b1 << 2) | ((b2 & 0x30) >> 4);
            unsigned char c2 = ((b2 & 0x0F) << 4) | ((b3 & 0x3C) >> 2);
            unsigned char c3 = ((b3 & 0x03) << 6) | (b4 & 0x3F);

            output += c1;
            if (i + 2 < decoded.size()) output += c2;
            if (i + 3 < decoded.size()) output += c3;
        }

        return output;
    }
public:
    std::string base64(std::string date, bool mood) {
        std::string output;
        if (mood == true)output = base64_encode(date);
        else output = base64_decode(date);
        return output;
    }
};

std::string duru(std::string whereFile) {
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



int main(int argc, char* argv[]) {
    string whereFile;
    if (argv[1] != nullptr)whereFile = argv[1];
    else return -1;
    string data = duru(whereFile);
    string mood;
    if (argv[2] != nullptr)mood = argv[2];
    else return -1;
    short arrMY[5] = { 0,0,0,0,0 };
    string ls;
    if (mood == "jam") {
        for (short i = 0; i < 5; i++) {
            if (argv[i + 3] != nullptr)ls = argv[i + 3];
            else return -1;
            arrMY[i] = stoi(ls);
        }
        NNGMJ nngmj;
        NNGMJ::MYANDDATA jmdata = nngmj.Nngmj(data, arrMY[0], arrMY[1], arrMY[2], arrMY[3], arrMY[4]);
        cout << jmdata.Data << endl;
        xieru(whereFile + ".ack", jmdata.Data);
    }
    if (mood == "jem") {
        for (short i = 0; i < 5; i++) {
            if (argv[i + 3] != nullptr)ls = argv[i + 3];
            else return -1;
            arrMY[i] = stoi(ls);
        }
        NNGMJ nngmj;
        NNGMJ::MYANDDATA jemdata{ data,arrMY[0],arrMY[1],arrMY[2],arrMY[3],arrMY[4] };
        string jMdata = nngmj.Decrypt(jemdata);
        cout << jMdata << endl;
        std::string filePath;
        for (int i = 0; i < (whereFile.length() - 4); i++) {
            filePath += whereFile[i];
        }
        xieru(filePath, jMdata);
    }
    if (mood == "base64") {
        bool bmood;
        if (argv[3] != nullptr) {
            if (*argv[3] == '1')
            {
                bmood = true;
            }
            else {
                bmood = false;
            }

        }
        else return -1;
        if (bmood == true) {
            BASE64 base64;
            std::string output = move(base64.base64(move(duru(whereFile)), bmood));
            xieru(whereFile + ".base64", output);
        }
        if (bmood == false) {
            BASE64 base64;
            string output = move(base64.base64(move(duru(whereFile)), bmood));
            std::string filePath;
            for (int i = 0; i < (whereFile.length() - 6); i++)
            {
                filePath += whereFile[i];
            }
            xieru(filePath, output);
        }
    }
    if (mood == "shanlan") {
        bool bmood;
        if (argv[3] != nullptr) {
            if (*argv[3] == '1')
            {
                bmood = true;
            }
            else {
                bmood = false;
            }

        }
        else return -1;
        if (bmood == true) {
			ShanLan shanlan;
            std::string output = move(shanlan.shanlan(move(duru(whereFile)), bmood));
            xieru(whereFile + ".shanlan", output);
        }
        if (bmood == false) {
			ShanLan shanlan;
            string output = move(shanlan.shanlan(move(duru(whereFile)), bmood));
            std::string filePath;
            for (int i = 0; i < (whereFile.length() - 8); i++)
            {
                filePath += whereFile[i];
            }
            xieru(filePath, output);
        }
    }
    return 0;
}
