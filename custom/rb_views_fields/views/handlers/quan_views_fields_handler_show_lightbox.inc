<?php

/**
 * @file
 * Clase que maneja campo para abrir lightbox.
 */

/**
 * Clase manejadora de campo.
 */
class quan_views_fields_handler_show_lightbox extends views_handler_field {
  function admin_summary() { }
  function operator_form(&$form, &$form_state) {}
  function can_expose() {
    return FALSE;
  }

  /**
   * Dejamos el query vacío.
   */
  function query() {}

  /**
   * Renderizamos el contenido.
   */
  function render($values) {
    ctools_include('modal');
    ctools_modal_add_js();

    // ES VISTA DE USUARIO.
    if (isset($values->_field_data['uid']) && $values->_field_data['uid']['entity_type'] == 'user') {
      $type = $values->_field_data['uid']['entity_type'];
      $id = $values->uid;
    }
    // ES VISTA DE CONTENIDO.
    elseif (isset($values->_field_data['nid']) && $values->_field_data['nid']['entity_type'] == 'node') {
      $type = $values->_field_data['nid']['entity']->type;
      $id = $values->nid;
    }

    $link = <<<LINK
<a href="/modal/ajax/by-types/{$type}/{$id}/open" class="ctools-use-modal">
LINK;

    return $link;
  }
}
