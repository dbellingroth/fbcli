//
//  httpclient.h
//  facebookcli
//
//  Created by David Bellingroth on 19.02.12.
//  Copyright (c) 2012 Burbachstraße 5. All rights reserved.
//
#include <curl/curl.h>
#include <map>
#ifndef facebookcli_httpclient_h
#define facebookcli_httpclient_h

using namespace std;

class HTTPClient {
    CURL *curl;
    CURLcode res;
    string data;
    static string mapToPostFields(map<string,string> postfields);
    static size_t write_data(void *ptr, size_t size, size_t nmemb, void *ourpointer);
    void dataReceived(string);

public:
    string doGetRequest(string url);
    string doPostRequest(string url, map<string,string> postfields);
};


#endif
