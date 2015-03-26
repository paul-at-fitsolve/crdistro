<?php
/**
 * @file
 * cr_layout_base.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function cr_layout_base_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: wysiwyg
  $profiles['wysiwyg'] = array(
    'format' => 'wysiwyg',
    'editor' => 'ckeditor',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Underline' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Anchor' => 1,
          'Image' => 1,
          'Blockquote' => 1,
          'RemoveFormat' => 1,
          'Format' => 1,
          'Styles' => 1,
          'CreateDiv' => 1,
        ),
        'picture_ckeditor' => array(
          'picture_ckeditor' => 1,
        ),
        'drupal' => array(
          'node_embed' => 1,
          'break' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'default_toolbar_grouping' => 1,
      'verify_html' => 0,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 0,
      'remove_linebreaks' => 0,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 0,
      'block_formats' => 'span,p,h2,h3,h4,h5,h6,div,blockquote,u',
      'css_setting' => 'none',
      'css_path' => '',
      'css_classes' => 'CTA=a.cta
CTA (with tracking) = a.cta.addtracking
CTA (black)=a.cta.cta--black
CTA (black+tracking)=a.cta.cta--black.addtracking
CTA (cycle)=a.cta.cta--cycle
CTA (swim)=a.cta.cta--swim
CTA (need)=a.cta.cta--need
CTA (down)=a.cta.cta--down
Red Button=a.button
Red Button (with tracking)=a.button.addtracking
Red Button (colorbox)=a.button.colorbox-node
Red Button (track+colorbox)=a.button.addtracking.colorbox-node
Grey Button=a.button.button--grey
Grey Button (with tracking)=a.button.button--grey.addtracking
Light Grey Button=a.button.button--light-grey
Light Grey Button (with tracking)=a.button.button--light-grey.addtracking
Swim Button=a.button.button--swim
Swim Button (with tracking)=a.button.button--swim.addtracking
Run Button=a.button.button--run
Run Button (with tracking)=a.button.button--run.addtracking
Cycle Button=a.button.button--cycle
Cycle Button (with tracking)=a.button.button--cycle.addtracking
Red Button(lrg)=a.button.button--large
Grey Button(lrg)=a.button.button--grey.button--large
Swim Button(lrg)=a.button.button--swim.button--large
Swim Button(lrg+tracking)=a.button.button--swim.button--large.addtracking
Run Button(lrg)=a.button.button--run.button--large
Run Button(lrg+tracking)=a.button.button--run.button--large.addtracking
Cycle Button(lrg)=a.button.button--cycle.button--large
Cycle Button(lrg+tracking)=a.button.button--cycle.button--large.addtracking
Lead Image=div.image--lead
Lead Image Vertical Pull Out=div.image--lead.image--lead--vertical
Lead Paragraph=p.text--lead
Blockquote=blockquote.quote
Single Blue Blockquote=blockquote.quote--blue-single
FontColour (run)=span.font-color--run
FontColour (swim)=span.font-color--swim
FontColour (cycle)=span.font-color--cycle
FontColour Red=span.font-color--red
FontColour Blue=span.font-color--blue
FontColour Green=span.font-color--green
Medium Paragraph 14px=p.medium-paragraph
IMCircle (full)=div.circle
IMCircle (up)=span.circle--upper
IMCircle (down)=span.circle--down
Icon Span=span.icon
Full wdth Button=p.button--full-width
IMPrice (wrapper)=div.price
IMPrice (title)=div.price--title
IMPrice (bold)=span.price--bold
IMPrice (S)=span.price--normal
IMPrice (L)=span.price--large
addTracking=a.addtracking
Colorbox Node=a.colorbox-node
Colorbox Node (with tracking)=a.colorbox-node.addtracking',
      'advanced__active_tab' => 'edit-css',
    ),
  );

  return $profiles;
}
