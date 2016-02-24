//
//  User.swift
//  42profile
//
//  Created by Hugo CHERCHI on 2/20/16.
//  Copyright © 2016 Hugo CHERCHI. All rights reserved.
//

import Foundation
import JSONJoy

class User
{
    var id : Int?
    var email : String?
    var login : String?
    var url : String?
    var phone : String?
    var displayname : String?
    var image_url : String?
    var correction_point : Int?
    var location : String?
    var campus : Campus?
    var wallet : Int?
    var cursus : [Cursus]?
    var achievements : [Achievement]?
    
    init(_ decoder: JSONDecoder)
    {
        id = decoder["id"].integer
        email = decoder["email"].string
        login = decoder["login"].string
        url = decoder["url"].string
        phone = decoder["phone"].string
        image_url = decoder["image_url"].string
        correction_point = decoder["correction_point"].integer
        campus =  Campus(decoder["campus"])
        wallet = decoder["wallet"].integer
        location = decoder["location"].string
        if (self.location == nil)
        {
            self.location = "Unknown"
        }
        if let crs = decoder["cursus"].array
        {
            self.cursus = [Cursus]()
            for crsDecoder in crs
            {
                self.cursus?.append(Cursus(crsDecoder))
            }
        }
        if let ach = decoder["achievements"].array
        {
            self.achievements = [Achievement]()
            for achDecoder in ach
            {
                self.achievements?.append(Achievement(achDecoder))
            }
        }
    }
}

