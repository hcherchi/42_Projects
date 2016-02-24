//
//  Cursus.swift
//  42profile
//
//  Created by Hugo CHERCHI on 2/20/16.
//  Copyright © 2016 Hugo CHERCHI. All rights reserved.
//

import Foundation
import JSONJoy

class Cursus
{
    var cursus : SubCursus?
    var end_at : String?
    var level : Float?
    var grade : String?
    var projects : [Project]?
    var skills : [Skill]?
    
    init(_ decoder: JSONDecoder)
    {
        cursus = SubCursus(decoder["cursus"])
        end_at = decoder["end_at"].string
        level = decoder["level"].float
        grade = decoder["grade"].string
        if let pro = decoder["projects"].array
        {
            self.projects = [Project]()
            for proDecoder in pro
            {
                self.projects?.append(Project(proDecoder))
            }
        }
        if let ski = decoder["skills"].array
        {
            self.skills = [Skill]()
            for skiDecoder in ski
            {
                self.skills?.append(Skill(skiDecoder))
            }
        }
    }
}