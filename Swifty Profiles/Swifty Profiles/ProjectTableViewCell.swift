//
//  TableViewCell.swift
//  Swifty Profiles
//
//  Created by Hugo CHERCHI on 2/24/16.
//  Copyright © 2016 Hugo CHERCHI. All rights reserved.
//

import UIKit

class ProjectTableViewCell: UITableViewCell {

    @IBOutlet weak var projectname: UILabel!
    @IBOutlet weak var mark: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
}
