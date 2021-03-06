<?php
/**
 * @file
 * ik_channels.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ik_channels_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function ik_channels_image_default_styles() {
  $styles = array();

  // Exported image style: slide_images.
  $styles['slide_images'] = array(
    'name' => 'slide_images',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1920,
          'height' => 1080,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'slide_images',
  );

  // Exported image style: slide_logoes.
  $styles['slide_logoes'] = array(
    'name' => 'slide_logoes',
    'effects' => array(
      1 => array(
        'label' => 'Skalér',
        'help' => 'Skalering bevarer billedets højde-bredde-forhold. Hvis kun den ene dimension angives vil den anden blive beregnet.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 350,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'slide_logoes',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function ik_channels_node_info() {
  $items = array(
    'channel' => array(
      'name' => t('Kanal'),
      'base' => 'node_content',
      'description' => t('En kanal benyttes til at udvælge og præsentere slides.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
