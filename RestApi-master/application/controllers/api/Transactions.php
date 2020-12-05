<?php

defined('BASEPATH') OR exit('No direct script access allowed');


require APPPATH . 'libraries/REST_Controller.php';


class Transactions extends REST_Controller 
{

    function __construct()
    {
        //enable cors
        header('Access-Control-Allow-Origin: *');
        header("Access-Control-Allow-Methods: GET, POST, OPTIONS, PUT, DELETE");
        // Construct the parent class
        parent::__construct();

        $this->load->model('Transactions_model');
    }

    public function transactions_get()
    {
    // book from a data store e.g. database  
    
        $this->load->model('Transactions_model');

        $client_id = $this->get('client_id');
        $accType = $this->get('accType');
        /*$call_procedure= "CALL get_acc_events($client_id, $accType)";
        $data=array('CID'=>$client_id, 'AType'=>$accType);
        $query=$this->db->query($call_procedure, $data);*/
        $result=$this->Transactions_model->events($client_id, $accType);
        echo json_encode($result);

    }
        // If the id parameter doesn't exist return all books
       /* if ($client_id === NULL)
        {
            $transactions=$this->Transactions_model->post_transactions(NULL);
            // Check if the book data store contains book (in case the database result returns NULL)
            if ($transactions)
            {
                // Set the response and exit
                $this->response($transactions, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                // Set the response and exit
                $this->response([
                    'status' => FALSE,
                    'message' => 'No transactions were found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }

        // Find and return a single record for a particular user.
        else 
        {   
            // Validate the id.
            if ($client_id <= 0)
            {
                // Invalid id, set the response and exit.
                $this->response(NULL, REST_Controller::HTTP_BAD_REQUEST); // BAD_REQUEST (400) being the HTTP response code
            }

            // Get the user from the database, using the id as key for retrieval.
            $transactions=$this->Transactions_model->post_transactions($client_id);
            if (!empty($transactions))
            {
                $this->set_response($transactions, REST_Controller::HTTP_OK); // OK (200) being the HTTP response code
            }
            else
            {
                $this->set_response([
                    'status' => FALSE,
                    'message' => 'Transactions could not be found'
                ], REST_Controller::HTTP_NOT_FOUND); // NOT_FOUND (404) being the HTTP response code
            }
        }
    }*/
}
