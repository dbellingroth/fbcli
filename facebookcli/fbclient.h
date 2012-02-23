//
//  fbclient.h
//  facebookcli
//
//  Created by David Bellingroth on 19.02.12.
//  Copyright (c) 2012 Burbachstraße 5. All rights reserved.
//

#ifndef facebookcli_fbclient_h
#define facebookcli_fbclient_h
using namespace std;
class FBClient {
    string auth_token;
    string app_secret;
    
public:
    FBClient(string, string);
    ~FBClient();
    void printToken();
};


#endif
