<?php
function _cr_ig_get_predef_pledges($flat=FALSE) {
  $pledges = array ();
  $pledges['bake'] = array (
    array (
      'header' => 'Hold a bake sale',
      'body' => 'Bake some delicious cakes and sell them to friends and family to raise money',
    ),
    array (
      'header' => 'Give up your favourite food',
      'body' => 'Could you give up your favourite food for a whole day if people sponsor you? Or how about giving it up for a whole week?',
    ),
    array (
      'header' => 'Guess how many sweets in a jar',
      'body' => 'Fill a jar full of sweets and then challenge your friends to guess how many there are, charging £1 per guess. The winner keeps half the sweets and the rest are shared out- yum',
    ),
    array (
      'header' => 'Red Jelly Relay Race',
      'body' => 'Make some red jelly and put it on some plates, then hold a wobbly jelly relay race with your friends, charging everyone £1 to enter',
    ),
    array (
      'header' => 'Eat five doughnuts without licking your lips',
      'body' => 'Can you eat five doughnuts without licking your lips if people sponsor you? It\'s harder than it sounds!',
    )
  );
  
  $pledges['entertain'] = array (
    array (
      'header' => 'Set up your own Glee Club',
      'body' => 'Take inspiration from \'Comic Relief Does Glee Club?\' on CBBC and hold a Glee Club style performance at school or at home, selling tickets to raise cash.',
    ),
    array (
      'header' => 'Do a dance-a-thon ',
      'body' => 'How long can you dance non-stop for if everyone sponsors you?',
    ),
    array (
      'header' => 'Do a sing-a-thon',
      'body' => 'How would you feel about singing for a whole day, with no talking whatsoever? Have a go and ask friends and family to sponsor you.',
    ),
    array (
      'header' => 'Talent Show',
      'body' => 'Get your friends together and put on a talent show, charging people to come and watch the fun.',
    ),
    array (
      'header' => 'Dance-off competition',
      'body' => 'Hold a dance-off competition against a teacher or parent, getting friends and family to pay to watch.',
    )
  );
  
  $pledges['sell'] = array (
    array (
      'header' => 'Hold a jumble sale',
      'body' => 'Sell any old toys and clothes you don\'t want anymore by holding a jumble sale for friends and family.',
    ),
    array (
      'header' => 'Make your own joke book',
      'body' => 'Think of all your funniest jokes and write them up in your very own joke book which you sell to friends and family.',
    ),
    array (
      'header' => 'Make your own comic book',
      'body' => 'Make a book of your very own comic strips to sell to friends and family. Perhaps the Dinosesaurs could be the stars of your story?',
    ),
    array (
      'header' => 'Wash the dishes for a week',
      'body' => 'Ask a parent or guardian for a donation to Red Nose Day if you wash the dishes for an entire week.',
    ),
    array (
      'header' => 'Wash a car',
      'body' => 'Ask a parent or guardian if they\'ll give Red Nose Day a donation for you to wash their car. If you\'ve got the energy, they might have some friends who would let you clean theirs too.',
    ),
  );
  
  $pledges['dare'] = array (
    array (
      'header' => 'Wear a crazy wig',
      'body' => 'Could you do a hair dare like Jessie J? Ask friends and family to sponsor you to wear the silliest wig you can find for a day.',
    ),
    array (
      'header' => 'Give up your favourite TV show',
      'body' => 'Ask friends and family to sponsor you to give up your favourite TV show for a week.',
    ),
    array (
      'header' => 'Sponsored Silence',
      'body' => 'Can you stay silent for a whole day if your friends and family sponsor you?',
    ),
    array (
      'header' => 'Gunge your teacher',
      'body' => 'See if your teacher will take on a dare and be gunged on Red Nose Day in return for a £1 donation from everyone who wants a turn',
    ),
    array (
      'header' => 'Eat your most hated food',
      'body' => 'Ask your friends and family to sponsor you to eat the food you hate the most.',
    ),
  );
  $pledges['eighties'] = array (
    array (
      'header' => 'Spend the day on roller skates',
      'body' => 'Get friends and family to sponsor you to spend the whole day on roller skates.',
    ),
    array (
      'header' => 'Spend the day on a space hopper',
      'body' => 'Could you get sponsored to spend the day on a space hopper?',
    ),
    array (
      'header' => 'Wear leg warmers for the day',
      'body' => 'Get sponsored to wear bright leg warmers for a whole day. You could ask for extra money to wear them on your arms too!',
    ),
    array (
      'header' => 'Give up your games console',
      'body' => 'Back in the 80s, games consoles didn\'t exist.  See what life was like then by getting sponsored to give yours up for a whole week.',
    ),
    array (
      'header' => 'A disco night',
      'body' => 'Ask your teacher if your school can put on a disco night for you and your classmates, and charge everyone a small donation to come along.',
    ),
  );
  
  $pledges['dressup'] = array (
    array (
      'header' => 'Dress up as a superhero',
      'body' => 'Get sponsored to dress up as a superhero for the day.',
    ),
    array (
      'header' => 'Wear your pyjamas all day',
      'body' => 'See if your friends and family will sponsor you to wear your pyjamas all day long.',
    ),
    array (
      'header' => 'Ditch your uniform',
      'body' => 'Ask your teacher if you and your classmates can all pay £1 each to ditch your school uniform and wear what you want for a day',
    ),
    array (
      'header' => 'Dress up as a pop star',
      'body' => 'Get your friends and family to sponsor you to dress up as a pop star or band for a whole day.',
    ),
    array (
      'header' => 'Wear red all day',
      'body' => 'Ask around for sponsors to wear as many red pieces of clothing as possible, all day long.',
    ),
  );
  
  $pledges['challenge'] = array (
    array (
      'header' => 'Walk to school for a week',
      'body' => 'Get friends and family to sponsor you to walk to school for a week. Make sure you always find a grown-up to walk with you.',
    ),
    array (
      'header' => 'A three-legged day',
      'body' => 'Tie yourself to a friend for the day, and ask your friends and family to sponsor you.',
    ),
    array (
      'header' => 'A skip-a-thon',
      'body' => 'Grab a skipping rope and get sponsored to skip for as long as you can in a skip-a-thon.',
    ),
    array (
      'header' => 'Sponsored Bike Ride',
      'body' => 'How far can you cycle? Ask friends and family to sponsor your cycling challenge.',
    ),
    array (
      'header' => 'Games console competition',
      'body' => 'Hold a games console competition and charge friends and family to enter.',
    ),
  );

  $new_pledges = array();  
  
  if ($flat) {
    foreach ($pledges as $cat_pledges) {
      $new_pledges = array_merge($new_pledges, $cat_pledges);

    }
  }
  else {
    $i = 0;
    foreach ($pledges as $cat => $cat_pledges) {
      foreach($cat_pledges as $pledge) {
        $new_pledges[$cat][] = array_merge(array('id' => $i), $pledge);
        $i++;
      }
    }
  }
  return $new_pledges;
}
