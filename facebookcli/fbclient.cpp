//
//  fbclient.cpp
//  facebookcli
//
//  Created by David Bellingroth on 19.02.12.
//  Copyright (c) 2012 Burbachstraße 5. All rights reserved.
//

#include <iostream>
#include "fbclient.h"
using namespace std;

FBClient::FBClient(string secret, string token):app_secret(secret) ,auth_token(token) {
    
}

FBClient::~FBClient() {
    
}

void FBClient::printToken() {
    cout << auth_token << endl;
}