//
//  SkillCellTableViewCell.swift
//  Swifty Profiles
//
//  Created by Hugo CHERCHI on 2/25/16.
//  Copyright © 2016 Hugo CHERCHI. All rights reserved.
//

import UIKit

class SkillTableViewCell: UITableViewCell {

    @IBOutlet weak var skilllevel: UILabel!
    @IBOutlet weak var skillbar: UIProgressView!
    @IBOutlet weak var skillname: UILabel!
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
