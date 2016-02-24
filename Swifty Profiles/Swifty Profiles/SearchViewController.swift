//
//  ViewController.swift
//  Swifty Profiles
//
//  Created by Hugo CHERCHI on 2/22/16.
//  Copyright © 2016 Hugo CHERCHI. All rights reserved.
//

import UIKit

class SearchViewController: UIViewController
{
    @IBOutlet weak var input: UITextField!
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
    }
    
    @IBAction func enter()
    {
        getInfo(input.text!)
    }
    
    @IBAction func search()
    {
        getInfo(input.text!)
    }
    
    func getInfo(login : String)
    {
        API.getToken(login)
        while Globals.usr == nil
        {
            
        }
        performSegueWithIdentifier("ProfileViewSegue", sender : nil)
    }
}

