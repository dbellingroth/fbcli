//
//  httpclient.cpp
//  facebookcli
//
//  Created by David Bellingroth on 19.02.12.
//  Copyright (c) 2012 Burbachstraße 5. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "httpclient.h"
#include <curl/curl.h>


using namespace std;

string HTTPClient::doGetRequest(string url) {
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);
        data = string("");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    if (res == 0) return data;
    else return NULL;
}

string HTTPClient::doPostRequest(string url, map<string,string> postfields) {
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, this);
        data = string("");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, mapToPostFields(postfields).c_str());
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    if (res == 0) return data;
    else return NULL;
}

string HTTPClient::mapToPostFields(map<string,string> postfields){
    string pf = "";
    map<string,string>::iterator p;
    for(p = postfields.begin(); p != postfields.end(); p++) {
        if (p != postfields.begin()) pf += "&";
        pf = pf + p->first + "=" + p->second;
    }
    cout << pf << endl;
    return pf;
}

size_t HTTPClient::write_data(void *ptr, size_t size, size_t nmemb,   void *object)   {
    long realsize = size * nmemb;
    //char received[realsize];
    //memcpy(received, ptr, realsize); 
    ((HTTPClient*)object)->dataReceived(string((char*)ptr));
    return realsize;
}

void HTTPClient::dataReceived(string _data) {
    data += _data;
}