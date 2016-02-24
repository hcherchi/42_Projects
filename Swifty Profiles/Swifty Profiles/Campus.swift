//
//  Campus.swift
//  42profile
//
//  Created by Hugo CHERCHI on 2/20/16.
//  Copyright © 2016 Hugo CHERCHI. All rights reserved.
//

import Foundation
import JSONJoy

class Campus
{
    var id : Int?
    var name : String?
    var created_at : String?
    var updated_at : String?
    var time_zone : String?
    var language_id : Int?
    var slug : String?
    
    init(_ decoder: JSONDecoder)
    {
        id = decoder["id"].integer
        name = decoder["name"].string
        created_at = decoder["created_at"].string
        updated_at = decoder["updated_at"].string
        time_zone = decoder["time_zone"].string
        language_id = decoder["language_id"].integer
        slug = decoder["slug"].string
    }
}
