<?php
session_start();

include('database_operations.php');
$database = connect_database();
$categories = get_categories($database);
close_database($database);

?>
<header>
 	<a class="titlelink" href="index.php">Guitar & Co.</a>
    <div class = "header-content">
        <ul id="menu">
			<li><a href="#">Instruments</a>
				<ul>
				<?php
				foreach ($categories as $val)
				{
					if ($val['categorie-master'] == "1")
					{
					?>
						<li><a href="products.php?category=<?php echo $val['name']; ?>"><?php echo $val['name']; ?></a></li>
					<?php
					}
				}
				?>
				</ul>
			</li>
			<li><a href="#">Accessoires</a>
				<ul>
				<?php
				foreach ($categories as $val)
				{
					if ($val['categorie-master'] == "2")
					{
					?>
						<li><a href="products.php?category=<?php echo $val['name']; ?>"><?php echo $val['name']; ?></a></li>
					<?php
					}
				}
				?>
				</ul>
			</li>
			<li><a href="#">Vinyles</a>
				<ul>
				<?php
				foreach ($categories as $val)
				{
					if ($val['categorie-master'] === "3")
					{
					?>
						<li><a href="products.php?category=<?php echo $val['name']; ?>"><?php echo $val['name']; ?></a></li>
					<?php
					}
				}
				?>
				</ul>
			</li>
		</ul>
		<nav>
                <ul>
<?php
					if ($_SESSION["user"] === "" || empty($_SESSION))
					{
?>
						<li><a href="connect.php">Connexion</a></li>
						<li><a href="register.php">Inscription</a></li>
<?php
					}
					else
					{
?>
						<li><a href="account.php">Compte</a></li>
						<li><a href="logout.php">Deconnection</a></li>
<?php
					}
?>
                </ul>
        </nav>
		</div>
</header>