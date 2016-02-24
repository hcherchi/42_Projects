//
//  Project.swift
//  42profile
//
//  Created by Hugo CHERCHI on 2/21/16.
//  Copyright © 2016 Hugo CHERCHI. All rights reserved.
//

import Foundation
import JSONJoy

class Project
{
    var id : Int?
    var name : String?
    var registered_at : String?
    var slug : String?
    var final_mark : Int?
    var occurence : Int?
    var projects_user_id : Int?
    var retriable_at : String?
    //var teams_ids : [Int]?
    
    init(_ decoder: JSONDecoder)
    {
        id = decoder["id"].integer
        name = decoder["name"].string
        registered_at = decoder["registered_at"].string
        slug = decoder["slug"].string
        final_mark = decoder["final_mark"].integer
        occurence = decoder["occurence"].integer
        projects_user_id = decoder["projects_user_id"].integer
        retriable_at = decoder["retriable_at"].string
        //teams_ids = decoder["teams_ids"].integer
    }
}