//
//  Token.swift
//  42profile
//
//  Created by Hugo CHERCHI on 2/20/16.
//  Copyright © 2016 Hugo CHERCHI. All rights reserved.
//

import Foundation
import JSONJoy

class Token
{
    var access_token : String?
    var token_type : String?
    var expires_in : Int?
    var created_at : Int?
    
    init(_ decoder: JSONDecoder) throws
    {
        access_token = try decoder["access_token"].getString()
        token_type = try decoder["token_type"].getString()
        expires_in = try decoder["expires_in"].getInt()
        created_at = try decoder["created_at"].getInt()
    }
}
