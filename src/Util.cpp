/*
 * @Author: diehl wei.jiacheng@diehl.com
 * @Date: 2022-11-22 10:59:01
 * @LastEditors: diehl wei.jiacheng@diehl.com
 * @LastEditTime: 2022-12-15 16:43:27
 * @FilePath: \VirtualMachineCpp\src\Util.cpp
 * @Description: 公共工具类实现文件
 */
#include "Util.h"
#include "nlohmann/json.hpp"
using namespace std;

unique_ptr<Util> Util::m_util = std::move(unique_ptr<Util>(new Util()));

using json = nlohmann::json;

void Util::Dir(std::string path)
{
    long hFile = 0;
    struct _finddata_t fileInfo;
    string pathName, exdName;
    // \\* 代表要遍历所有的类型,如改成\\*.jpg表示遍历jpg类型文件

    // cout<<"A "<<pathName.assign(path).append("\\*").c_str()<<endl;

    if ((hFile = _findfirst(pathName.assign(path).append("\\*").c_str(), &fileInfo)) == -1)
    {
        return;
    }
    do
    {
        //判断文件的属性是文件夹还是文件
        cout << fileInfo.name << (fileInfo.attrib & _A_SUBDIR ? "[folder]" : "[file]") << endl;
    } while (_findnext(hFile, &fileInfo) == 0);
    _findclose(hFile);
    return;
}
// 从文件中返回json 对象
json Util::GetJsonFromFile(const string &file)
{
    std::ifstream ifs(file);
    json json_from_file = json::parse(ifs);  
    string str = json_from_file.dump();
    // cout<<"json from file "<<str<<endl;

    return json_from_file;
}

Util *Util::GetIns()
{
    if (m_util != nullptr)
    {
        return m_util.get();
    }
    else
    {
        cout << " What fk" << endl;
        return nullptr;
    }
}

//从目录中获取指定格式文件的 文件名称list
vector<string> Util::GetFileNameByFormatUnderDir(const string &dir_path, const string &file_format)
{
    vector<string> res{};

	//文件句柄
	//注意：我发现有些文章代码此处是long类型，实测运行中会报错访问异常
	intptr_t hFile = 0;

   // long hFile = 0;
   
    struct _finddata_t fileInfo;

    string pathName, exdName;
    // \\* 代表要遍历所有的类型,如改成\\*.jpg表示遍历jpg类型文件

    string filter = dir_path + "\\*" + "." + file_format;

    //  if ((hFile = _findfirst(pathName.assign(dir_path).append("\\*").c_str(), &fileInfo)) == -1)
    if ((hFile = _findfirst(filter.c_str(), &fileInfo)) == -1)
    {
        return res;
    }
    
    do
    {
        //判断文件的属性是文件夹还是文件
      //  cout << fileInfo.name << (fileInfo.attrib & _A_SUBDIR ? "[folder]" : "[file]") << endl;
      //  cout<<" string(fileInfo.name) "<<string(fileInfo.name)<<endl;
        res.push_back(string(fileInfo.name));

    } while (_findnext(hFile, &fileInfo) == 0);
    _findclose(hFile);

    return res;
}
#if 0
void getFileNames(const string& path, vector<string>& files)
{
	//文件句柄
	//注意：我发现有些文章代码此处是long类型，实测运行中会报错访问异常
	intptr_t hFile = 0;
	//文件信息
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,递归查找
			//如果不是,把文件绝对路径存入vector中
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					getFileNames(p.assign(path).append("\\").append(fileinfo.name), files);
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}
#endif 