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
    @IBOutlet weak var error: UILabel!
    @IBOutlet weak var input: UITextField!
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
    }
    
    func cleanCursus()
    {
        var i = 0
        while (i < Globals.usr?.cursus?.count)
        {
            if Globals.usr?.cursus?[i].cursus?.name != "42"
            {
                Globals.usr?.cursus?.removeAtIndex(i)
            }
            else
            {
                i++;
            }
        }
    }
    @IBAction func search()
    {
        Globals.usr = nil
        error.text = ""
        
        ////////IF NEED TO GET TOKEN AGAIN THEN DO
        let sema1 = dispatch_semaphore_create(0);
        API.getToken(sema1)
        dispatch_semaphore_wait(sema1, DISPATCH_TIME_FOREVER);
        /////////
        
        let sema2 = dispatch_semaphore_create(0);
        API.getUser(input.text, sema: sema2)
        dispatch_semaphore_wait(sema2, DISPATCH_TIME_FOREVER);
        
        if Globals.usr!.id != nil
        {
            cleanCursus()
            performSegueWithIdentifier("ProfileViewSegue", sender : nil)
        }
        else
        {
            error.text = "Invalid User..."
            error.textColor = UIColor.redColor()
        }
    }
}

