//
//  ProfileViewController.swift
//  Swifty Profiles
//
//  Created by Hugo CHERCHI on 2/22/16.
//  Copyright © 2016 Hugo CHERCHI. All rights reserved.
//

import UIKit

class ProfileViewController: UIViewController {
    
    @IBOutlet weak var bg: UIImageView!
    @IBOutlet weak var profileview: UIView!
    @IBOutlet weak var photo: UIImageView!
    @IBOutlet weak var scrollview: UIScrollView!
    @IBOutlet weak var projectsview: UIView!
    @IBOutlet weak var skillsview: UIView!
    @IBOutlet weak var login: UILabel!
    @IBOutlet weak var fullname: UILabel!
    @IBOutlet weak var location: UILabel!
    @IBOutlet weak var phone: UILabel!
    @IBOutlet weak var email: UILabel!
    @IBOutlet weak var points: UILabel!
    @IBOutlet weak var wallets: UILabel!
    @IBOutlet weak var lvl: UILabel!
    @IBOutlet weak var bar: UIProgressView!
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
        
        let url = NSURL(string: (Globals.usr?.image_url)!)
        let data = NSData(contentsOfURL: url!)
        photo.image = UIImage(data: data!)
        photo.contentMode = UIViewContentMode.ScaleAspectFill
        photo.layer.cornerRadius = photo.frame.size.width / 2
        photo.layer.borderWidth = 3.0
        photo.layer.borderColor = UIColor.whiteColor().CGColor
        
        let f = Globals.usr?.cursus![1].level
        let lvlstr = f!.description
        login.text = Globals.usr?.login
        phone.text = Globals.usr?.phone
        email.text = Globals.usr?.email
        location.text = Globals.usr?.location
        lvl.text = "level " + lvlstr + "%"
        bar.progress = f! - floor(f!)
        bar.layer.cornerRadius = 15
        fullname.text = Globals.usr?.displayname
        points.text = (Globals.usr?.correction_point?.description)! + " C.P"
        wallets.text = (Globals.usr?.wallet?.description)! + " ₩"
    }
    
    override func viewWillLayoutSubviews()
    {
        super.viewWillLayoutSubviews();
        self.scrollview.contentSize.height = profileview.frame.height + projectsview.frame.height + skillsview.frame.height + 70
    }
}
