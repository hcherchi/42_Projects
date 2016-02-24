//
//  SubCursus.swift
//  42profile
//
//  Created by Hugo CHERCHI on 2/21/16.
//  Copyright © 2016 Hugo CHERCHI. All rights reserved.
//

import Foundation
import JSONJoy

class SubCursus
{
    var id : Int?
    var name : String?
    var created_at : String?
    var updated_at : String?
    var slug : String?
    
    init(_ decoder: JSONDecoder)
    {
        id = decoder["id"].integer
        name = decoder["name"].string
        created_at = decoder["created_at"].string
        updated_at = decoder["updated_at"].string
        slug = decoder["slug"].string
    }
}