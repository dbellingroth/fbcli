//
//  main.cpp
//  facebookcli
//
//  Created by David Bellingroth on 19.02.12.
//  Copyright (c) 2012 Burbachstraße 5. All rights reserved.
//

#include <iostream>
#include "fbclient.h"
#include "httpclient.h"
#include "../rapidjson/document.h"
#include "../rapidjson/prettywriter.h"

using namespace std;
int main (int argc, const char * argv[])
{
    string token("AAACEdEose0cBAJEloIrKapHOJYf0KZCLiqN18xPY3tOcdsFGNxr5vWRlZACGiHB9qFpBbiyQHulw7DqAYZCR44clcfRxoZCilfUHnZBKPg8QHs3t7ETob");
    HTTPClient http;
    map<string,string> params;
    params.insert(pair<string,string>(string("value"),string("key")));
    
    rapidjson::Document document;
    document.Parse<0>(http.doGetRequest(string("https://graph.facebook.com/me/friends?access_token="+token)).c_str());
    
    cout << document["data"][0u]["name"].GetString();
    
    return 0;
}