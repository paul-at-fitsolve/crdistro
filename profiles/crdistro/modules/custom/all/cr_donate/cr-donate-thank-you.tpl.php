<p><strong>Merchants Reference:</strong> <?php print $cart_id; ?></p>
<?php if ($paypal): ?>
<p><strong>PayPal Transaction ID:</strong> <?php print $transaction_id; ?></p>
<?php else: ?>
<p><strong>WorldPay Transaction ID:</strong> <?php print $transaction_id; ?></p>
<?php endif; ?>
