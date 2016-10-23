<?php

function connect_database()
{
	$database = mysqli_connect("mysql-rush00.alwaysdata.net", "rush00_bkabbas", "bkabbas77");
	if (!$database)
		die("Impossible de se connecter : ".mysqli_error($database));
	mysqli_select_db($database, "rush00_database");
	return ($database);
}

function close_database($database)
{
	mysqli_close($database);
	unset($database);
}

function add_user($database, $user, $pass)
{
	$user = mysqli_real_escape_string($database, $user);
	$pass = mysqli_real_escape_string($database, $pass);
	$request = "INSERT INTO users (username, password) VALUES ('$user', '$pass')";
	if (!mysqli_query($database, $request))
		echo 'Error while doing request: '.mysqli_error($database);
}

function delete_user($database, $id)
{
	$id = mysqli_real_escape_string($database, $id);
	$request = "DELETE FROM users WHERE id='$id'";
	if (!mysqli_query($database, $request))
		echo "Error removing user from database";
}

function delete_user_by_name($database, $name)
{
	$name = mysqli_real_escape_string($database, $name);
	$request = "DELETE FROM users where username='$name'";
	if (!mysqli_query($database, $request))
		echo "Error removing user from database";
}

function user_already_exist($database, $user)
{
	$user = mysqli_real_escape_string($database, $user);
	$request = "SELECT * FROM users WHERE username='$user'";
	$sql = mysqli_query($database, $request);
	if (mysqli_num_rows($sql) >= 1)
		return (true);
	else
		return (false);
}

function change_password($database, $user, $new_pass)
{
	$user = mysqli_real_escape_string($database, $user);
	$pass = mysqli_real_escape_string($database, $new_pass);

	$request = "UPDATE users SET password='$new_pass' WHERE username='$user'";
	if (!mysqli_query($database, $request))
		echo 'Error while doing request: '.mysqli_error($database);
}

function authenticate($database, $user, $pass, &$ret_row)
{
	$user = mysqli_real_escape_string($database, $user);
	$pass = mysqli_real_escape_string($database, $pass);
	$request = "SELECT * FROM users WHERE username='$user'";

	$sql = mysqli_query($database, $request);
	$numrows = mysqli_num_rows($sql);
	if ($numrows != 0)
	{
		while ($row = mysqli_fetch_assoc($sql))
		{
			if ($row['password'] === $pass)
			{
				$ret_row = $row;
				return (true);
			}
		}
	}
	return (false);
}

function get_users($database)
{
	$users = array();
	$request = "SELECT * FROM users";
	$sql = mysqli_query($database, $request);
	while ($row = mysqli_fetch_assoc($sql))
	$users[] = $row;
	return $users;
}

function get_items($database)
{
	$items = array();
	$request = "SELECT * FROM items";
	$sql = mysqli_query($database, $request);
	while ($row = mysqli_fetch_assoc($sql))
			$items[] = $row;
	return $items;
}

function delete_item($database, $id)
{
	$id = mysqli_real_escape_string($database, $id);
	$request = "DELETE FROM items WHERE id='$id'";
	if (!mysqli_query($database, $request))
		echo "Error removing item from database";
}

function update_item($database, $id, $row)
{
	$id = mysqli_real_escape_string($database, $id);
	$name = mysqli_real_escape_string($database, $row["name"]);
	$desc = mysqli_real_escape_string($database, $row["description"]);
	$cate = mysqli_real_escape_string($database, $row["categories"]);
	$price = mysqli_real_escape_string($database, $row["price"]);
	$img = mysqli_real_escape_string($database, $row["image_url"]);
	$request = "UPDATE items SET name='$name', description='$desc', categories='$cate', price='$price', image_url='$img' WHERE id='$id'";
	if (!mysqli_query($database, $request))
		echo "Error updating item to database";
}

function get_item_by_id($database, $id)
{
	$id = mysqli_real_escape_string($database, $id);
	$request = "SELECT * FROM items WHERE id='$id'";
	$sql = mysqli_query($database, $request);
	if (mysqli_num_rows($sql) >= 1)
		return mysqli_fetch_assoc($sql);
	else
		echo "error";
}

function create_item($database, $row)
{
	$name = mysqli_real_escape_string($database, $row["name"]);
	$desc = mysqli_real_escape_string($database, $row["description"]);
	$cate = mysqli_real_escape_string($database, $row["categories"]);
	$price = mysqli_real_escape_string($database, $row["price"]);
	$img = mysqli_real_escape_string($database, $row["image_url"]);
	$request = "INSERT INTO items (name, description, categories, price, image_url)
				VALUES ('$name', '$desc', '$cate', '$price', '$img')";
	if (!mysqli_query($database, $request))
		echo "Error adding item to database";
}



function get_categories($database)
{
	$items = array();
	$request = "SELECT * FROM categories";
	$sql = mysqli_query($database, $request);
	while ($row = mysqli_fetch_assoc($sql))
			$items[] = $row;
	return $items;
}


function create_categorie($database, $row)
{
	$name = mysqli_real_escape_string($database, $row["name"]);
	$master = mysqli_real_escape_string($database, $row["categorie-master"]);
	$request = "INSERT INTO categories (name, categorie-master)
				VALUES ('$name', '$master')";
	if (!mysqli_query($database, $request))
		echo "Error adding item to database";
}

function delete_categorie($database, $id)
{
	$id = mysqli_real_escape_string($database, $id);
	$request = "DELETE FROM categories WHERE id='$id'";
	if (!mysqli_query($database, $request))
		echo "Error removing categories from database";
}

function is_inside_basket($array, $item)
{
	foreach ($array as $val)
	{
		if ($val['item'] === $item)
		{
			return (true);
		}
	}
	return (false);
}

function get_basket_item($array, $id)
{
	$i = 0;
	foreach ($array as $val)
	{
		if ($val['item']['id'] === $id)
			return $i;
		$i++;
	}
	return (-1);
}

function get_basket_price($array)
{
	$price;
	
	foreach($array as $val)
		$price += $val['item']['price'];
	return ($price);
}

function get_command($database)
{
	$command = array();
	$request = "SELECT * FROM command";
	$sql = mysqli_query($database, $request);
	while ($row = mysqli_fetch_assoc($sql))
			$command[] = $row;
	return $command;
}

function create_command($database, $row)
{
	$price = mysqli_real_escape_string($database, $row["price"]);
	$date = ('d-m-Y H:i');
	$user = mysqli_real_escape_string($database, $row["user"]);
	$request = "INSERT INTO command (price, date, user)
				VALUES ('$name', '$date', '$user')";
	if (!mysqli_query($database, $request))
	{
		echo "Error adding item to database".mysqli_error($database);
		return (false);
	}
	return (true);
}

?>