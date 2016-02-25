//
//  API.swift
//  42profile
//
//  Created by Hugo CHERCHI on 2/20/16.
//  Copyright © 2016 Hugo CHERCHI. All rights reserved.
//

import Foundation
import SwiftHTTP
import JSONJoy

class API
{
    static let APIURL = "https://api.intra.42.fr"
    static let APIURLOAUTH = APIURL + "/oauth/token"
    static let APIURLUSER = APIURL + "/v2/users/"
    static let uid = "6b119b0e9d3b8dcc85e4b7bdad79a0f60006caec2753e68b18b39a05f6445b06"
    static let secret = "38dccb6398bd6ab9358b3daf19c33000069da0b5f93a4b7a1731a05365f6d71c"
    
    static func getToken(sema :dispatch_semaphore_t!)
    {
        
        let params = ["grant_type" : "client_credentials", "client_id" : API.uid, "client_secret" : API.secret]
        do
        {
            let opt = try HTTP.POST(API.APIURLOAUTH, parameters: params)
            opt.start
            {
                response in
                if let error = response.error
                {
                    print("got an error: \(error)")
                }
                do
                {
                    Globals.token = try Token(JSONDecoder(response.data))
                    dispatch_semaphore_signal(sema);
                }
                catch
                {
                    print("unable to parse the JSON")
                }
            }
        }
        catch let error
        {
            print("got an error creating the request: \(error)")
        }
    }
    
    static func getUser(user : String?, sema :dispatch_semaphore_t!)
    {
        do
        {
            let opt = try HTTP.GET(API.APIURLUSER + user!, parameters: nil, headers: ["Authorization" : (Globals.token?.token_type ?? "") + " " + (Globals.token?.access_token ?? "")])
            opt.start
            {
                response in
                if let error = response.error
                {
                    print("got an error: \(error)")
                }
                do
                {
                    Globals.usr = User(JSONDecoder(response.data))
                    dispatch_semaphore_signal(sema);
                }
            }
        }
        catch let error
        {
            print("got an error creating the request: \(error)")
        }
    }
}