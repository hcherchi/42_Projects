//
//  Achievement.swift
//  42profile
//
//  Created by Hugo CHERCHI on 2/21/16.
//  Copyright © 2016 Hugo CHERCHI. All rights reserved.
//

import Foundation
import JSONJoy

class Achievement
{
    var id : Int?
    var name : String?
    var description : String?
    var users_url : String?
    
    init(_ decoder: JSONDecoder)
    {
        id = decoder["id"].integer
        name = decoder["name"].string
        description = decoder["description"].string
        users_url = decoder["users_url"].string
    }
}