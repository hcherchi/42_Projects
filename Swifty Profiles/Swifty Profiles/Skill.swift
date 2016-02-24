//
//  Skill.swift
//  42profile
//
//  Created by Hugo CHERCHI on 2/21/16.
//  Copyright © 2016 Hugo CHERCHI. All rights reserved.
//

import Foundation
import JSONJoy

class Skill
{
    var id : Int?
    var name : String?
    var level : Float?
    
    init(_ decoder: JSONDecoder)
    {
        id = decoder["id"].integer
        name = decoder["name"].string
        level = decoder["level"].float
    }
}