<?php
/**
 *
 */
class Client_model extends CI_model
{
  function get_client($id){
    $this->db->select('*');
    $this->db->from('client');
    if($id !== NULL) {
      $this->db->where('idClient',$id);
    }
    return $this->db->get()->result_array();
  }
  function add_client($add_data){
    $this->db->query("CALL add_client (?,?,?,?,?)",$add_data);
    if($this->db->affected_rows()!==NULL){
      return $this->db->affected_rows();
    }
    else {
      return FALSE;
    }
  }
  function update_client($id, $update_data){
    $this->db->where('idClient',$id);
    $this->db->update('client',$update_data);
    if($this->db->affected_rows()>0){
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  function delete_client($id){
    $this->db->where('idClient',$id);
    $this->db->delete("client");

    if($this->db->affected_rows()>0){
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  function check_login($username){
    $this->db->select('password');
    $this->db->from('client');
    $this->db->where('username',$username);
    return $this->db->get()->row('password');
  }
  

}
