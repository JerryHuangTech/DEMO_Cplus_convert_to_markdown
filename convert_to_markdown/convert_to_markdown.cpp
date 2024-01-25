#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <Windows.h>
#include <cassert>
#include <vector>

using namespace std;

// 定義可以客製化的名稱
map<string, string> extension_mapping = {
    { "py", "Python" },
    { "ts", "Typescript" }
};

string UTF8ToUnicode(const char* str)
{
    string result;
    WCHAR* strSrc;
    LPSTR szRes;

    //UT8轉unicode 
    int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
    strSrc = new WCHAR[i + 1];
    MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

    //WChar轉回Char
    i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
    szRes = new CHAR[i + 1];
    WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

    result = szRes;
    delete[]strSrc;
    delete[]szRes;

    return result;
}

std::string readFile(std::string file)
{
    std::ifstream infile;
    infile.open(file.data());   
    assert(infile.is_open());   

    string s; string strAllLine;
    while (getline(infile, s)) {
        string line = UTF8ToUnicode(s.c_str()).c_str();
        strAllLine += line+"\n";
    }

    infile.close(); 
    return strAllLine;
}

//轉為markdown
string convert_to_markdown(string file_path) {
    try {
        string file_name = file_path.substr(file_path.find_last_of("\\/") + 1);
        string file_extension = file_name.substr(file_name.find_last_of(".") + 1);
        string lang = "";

        // 獲取文件 MIME 類型
        string mime_type = "";

        ifstream file(file_path);
        if (file) {
            char buffer[256];
            file.read(buffer, 256);
            streamsize bytesRead = file.gcount();
            mime_type = string(buffer, bytesRead);
        }
        file.close();

        // 依據MIM取得語言名稱
        size_t start = mime_type.find(": ");
        if (start != string::npos) {
            start += 2;
            size_t end = mime_type.find("\r\n", start);
            if (end != string::npos) {
                string mime_type_str = mime_type.substr(start, end - start);
                size_t pos = mime_type_str.find("/");
                if (pos != string::npos) {
                    lang = mime_type_str.substr(pos + 1);
                }
            }
        }

        // 自訂附檔名
        auto iter = extension_mapping.find(file_extension);
        if (iter != extension_mapping.end()) {
            lang = iter->second;
        }

        // 如果還是為空就用副檔名
        if (lang.empty()) {
            lang = file_extension;
        }

        // 文件內容
        string content = readFile(file_path);

        // 組合成markdown
        string markdown_output = "`" + file_path + "`\n\n```" + lang + ":" + file_name + "\n" + content + "\n```\n\n";
        return markdown_output;
    }
    catch (exception& e) {
        return "";
    }
}

int main(int argc, char* argv[]) {

    // 抓資料並轉換
    string file_path = argv[1];
    string markdown_output = convert_to_markdown(file_path);

    //若不為空，處理後貼到剪貼簿
    if (!markdown_output.empty()) {
        if (OpenClipboard(NULL)) {
            EmptyClipboard();
            HGLOBAL clipbuffer;
            char* buffer;
            clipbuffer = GlobalAlloc(GMEM_DDESHARE, markdown_output.length() + 1);
            buffer = (char*)GlobalLock(clipbuffer);
            strcpy_s(buffer, markdown_output.length() + 1, markdown_output.c_str());
            GlobalUnlock(clipbuffer);
            SetClipboardData(CF_TEXT, clipbuffer);
            CloseClipboard();
        }
    }
    return 0;
}
