#ifndef REQUEST_HPP
# define REQUEST_HPP

# include "include.hpp"

 


class Request{
public:
    Request();
    ~Request();
    Request(const Request& r);
    Request& operator=(const Request& r);
    void ParseRequest(int fd, std::string& buff);
    std::string&    GetMethod();
    std::string&    GetPath();
    std::string&    GetQuery();
    std::string&    GetVersion();
    std::multimap<std::string, std::string>& GetHeaders();
    std::string     GetHeader(const std::string& key);
    std::string&    GetBody();
	void 		  	SetPath(std::string& path);
    int             IsComplete();
    void            PrintRequest();
    int             GetFd();
    std::string&    GetHost();
    int             GetPort();
    int             GetStatus();
    std::string&    GetRemain();
    int             GetReqClose();
    std::string&    GetSpecificHeader(const std::string& key);
    void            SetComplete(int status);

    long long       GetTotalBytes();
    int             GetStage();
private: //essential
    std::string     m_buff;
    std::string     m_method;
    std::string     m_path;
    std::string     m_query;
    std::string     m_version;   
    std::multimap<std::string, std::string> m_headers;
    std::string     m_body;
    std::string     m_remain;
    std::string     m_host;
    int             m_status;
    int             m_origin_fd;
    int             m_host_port;
    int             m_startline_cnt;
    int             m_reqClose;
    int             m_readBodyLen;
    int             m_reqBodyLen;
    int             m_bodyLimit;
    int             m_contentLength;
    int             m_chunked;
    int             m_chunkedFlag;
    long long       m_totalBytes;
    int             m_stage;
    int             m_complete; // 완성했는가?
    int             m_end; // 더 저장할 필요가 있는가?
    void            parseStartline(const std::string& s);
    int             checkMethod(const std::string& s);
    int             checkVersion(const std::string& s);
    void            parseHeader(const std::string& s);
    int             check_key(const std::string& s);
    void            checkEssential();
    void            remove_ows(std::string& s);
    int             isNumber(const std::string& s);
    int             isHex(const std::string& s);
    long long       convertHex(const std::string& s);
    std::string     getLine(int start, std::string& s);
};

#endif