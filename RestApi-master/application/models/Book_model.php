<?php
/**
 *
 */
class Book_model extends CI_model
{
  //Hae kirjat tietokannasta
  function get_book($id){
    $this->db->select('*');
    $this->db->from('book');
    if($id !== NULL) {
      $this->db->where('id_book',$id);
    }
    return $this->db->get()->result_array();
  }
  //Lisää kirja tietokantaan
  function add_book($add_data){
    $this->db->insert('book',$add_data);
    if($this->db->insert_id()!==NULL){
      return $this->db->insert_id(); 
    }
    else {
      return FALSE;
    }  
  }
  //päivitä tietokannan tietoja
  function update_book($id, $update_data){
    $this->db->where('id_book',$id);
    $this->db->update('book',$update_data);
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }
//Tuhoa tietokannasta tietoja
  function delete_book($id){
    $this->db->where('id_book',$id);
    $this->db->delete('book');
    if($this->db->affected_rows()>0){
      return TRUE; 
    }
    else {
      return FALSE;
    }
  }


}


