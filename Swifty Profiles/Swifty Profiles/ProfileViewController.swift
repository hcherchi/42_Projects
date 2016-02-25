//
//  ProfileViewController.swift
//  Swifty Profiles
//
//  Created by Hugo CHERCHI on 2/22/16.
//  Copyright © 2016 Hugo CHERCHI. All rights reserved.
//

import UIKit

class ProfileViewController: UIViewController
{
    @IBOutlet weak var myskills: UITableView!
    @IBOutlet weak var myprojects: UITableView!
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
    @IBOutlet weak var year: UILabel!
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
        fillProfileView()
    }
    
    override func viewWillLayoutSubviews()
    {
        super.viewWillLayoutSubviews();
        self.scrollview.contentSize.height = profileview.frame.height + projectsview.frame.height + skillsview.frame.height
    }
    
    /*************
     Gere la Photo
     *************/
    
    func putPicture()
    {
        let url = NSURL(string: (Globals.usr?.image_url)!)
        let data = NSData(contentsOfURL: url!)
        photo.image = UIImage(data: data!)
        photo.contentMode = UIViewContentMode.ScaleAspectFill
        photo.layer.cornerRadius = photo.frame.size.width / 2
        photo.layer.borderWidth = 3.0
        photo.layer.borderColor = UIColor.whiteColor().CGColor
    }
    
    /************************
     Remplit la partie Profil
     ************************/
    
    func fillProfileView ()
    {
        putPicture()
        let f = Globals.usr?.cursus![0].level
        login.text = Globals.usr?.login
        phone.text = Globals.usr?.phone
        email.text = Globals.usr?.email
        location.text = Globals.usr?.location
        lvl.text = "LvL " + (Globals.usr?.cursus![0].level?.description)! + "%"
        bar.progress = f! - floor(f!)
        fullname.text = Globals.usr?.displayname
        points.text = (Globals.usr?.correction_point?.description)! + " Correction Points"
        wallets.text = (Globals.usr?.wallet?.description)! + " ₩allets"
        year.text = Globals.usr?.year
        
        myskills.layer.cornerRadius = 10
        myprojects.layer.cornerRadius = 10
    }
    
    /*****************************
     Nombre de Cell dans Tableview
     *****************************/
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int
    {
        if tableView == self.myprojects
        {
            return (Globals.usr?.cursus?[0].projects?.count)!;
        }
        else
        {
            return (Globals.usr?.cursus?[0].skills?.count)!;
        }
    }
    
    /********************
    Remplissage des Cells
    *********************/
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell
    {
        if tableView == self.myprojects
        {
            let cell: ProjectTableViewCell = self.myprojects.dequeueReusableCellWithIdentifier:forIndexPath:("projectCell", forIndexPath: indexPath) as! ProjectTableViewCell
            cell.mark.text = Globals.usr?.cursus?[0].projects?[indexPath.row].final_mark?.description
            cell.mark.textColor = (Globals.usr?.cursus?[0].projects?[indexPath.row].final_mark > 80) ? UIColor.greenColor() : UIColor.redColor()
            cell.projectname.text = Globals.usr?.cursus?[0].projects?[indexPath.row].name
            return cell
        }
        else
        {
            let cell: SkillTableViewCell = self.myskills.dequeueReusableCellWithIdentifier:forIndexPath:("skillCell", forIndexPath: indexPath) as! SkillTableViewCell
            let f: Float = (Globals.usr?.cursus?[0].skills?[indexPath.row].level)!
            cell.skillname.text = (Globals.usr?.cursus?[0].skills?[indexPath.row].name)!
            cell.skilllevel.text = (Globals.usr?.cursus?[0].skills?[indexPath.row].level?.description)! + "%"
            cell.skillbar.progress = f - floor(f)
            return cell
        }
    }
}
