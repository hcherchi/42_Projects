<?PHP
include("elements/header.php");

$database = connect_database();

$items = get_items($database);
$top = array();
foreach($items as $val)
{
	$categories = array_filter(explode(";", $val['categories']));
	if (in_array("top", $categories))
		$top[] = $val;
}

close_database($database);
?>
<!DOCTYPE html>
<html>
	<head>
		<link rel="stylesheet" type="text/css" href="index.css">
		<meta charset="UTF-8">
		<title>Guitar & Co</title>
	</head>
	<body>
		<section>
			<div class="vitrine">
			<h1 class="vitrinetitle">-  Top ventes  -</h1>
				<div class="elementsblock">
				<?php
					foreach($top as $top_item)
					{
					?>
						<div class="item">
							<img src="<?php echo $top_item['image_url'] ?>">
							<h1><?php echo $top_item['name'] ?></h1>
							<h2><?php echo $top_item['price'] ?></h2>
							<form action="add_basket.php" method="GET">
							<button type="submit" name="id" value="<?php echo $top_item["id"] ?>">Commander</button>
							</form>
						</div>
					<?php
					}
					?>
				</div>
			</div>
			<?PHP include("elements/panier.php"); ?>
		</section>
		<?PHP include("elements/footer.php"); ?>
	</body>
</html>